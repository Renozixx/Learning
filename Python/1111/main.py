# Leiam o README antes de prosseguir com a análise
import pandas as pd
from dotenv import load_dotenv
import os
import matplotlib.pyplot as plt
import numpy as np
from sklearn.ensemble import IsolationForest
import seaborn as sns
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay, classification_report
from sklearn.model_selection import train_test_split

print("Hello world")
# Pensando em Introduzir o Conceito de .env para vocês vou utilizar isso no nosso problema
# Basta criar um .env dentro da pasta e seguir as orientações presentes no .env.example
load_dotenv()

FILE_PATH = os.getenv('FILE_PATH')
print(FILE_PATH)

# Dataset disponível dentro do link do README
df = pd.read_csv(FILE_PATH)

df = df[df['machine_status'] != 'BROKEN']


df = df.drop(columns=['sensor_51', 'sensor_50', 'sensor_15', 'sensor_08', 'sensor_00', 'sensor_07', 'sensor_06', 'sensor_09'])

nan_por_coluna = df.isnull().sum()
print(nan_por_coluna)

counts = df.groupby('machine_status').size()
print(counts)

df = df.dropna()

counts = df.groupby('machine_status').size()
print(counts)

df["machine_status"] = df["machine_status"].replace({"NORMAL": 1, "RECOVERING": -1})

corr = df.corrwith(df['machine_status'], numeric_only=True)
# 2. Plota o heatmap da correlação
plt.figure(figsize=(12, 10))
corr_df = corr.to_frame().T
sns.heatmap(corr_df, annot=True, cmap="coolwarm", vmin=-1, vmax=1)

plt.title("Matriz de Correlação")
plt.show()

df = df.drop(df.index[40000:60000])

Y = df["machine_status"]
FEATS = df.drop(columns=['machine_status', 'timestamp', 'id'])

Feats_train, Feats_test, y_train, y_test = train_test_split(FEATS, Y, test_size=0.3, random_state=42)

iso = IsolationForest(
    n_estimators=1000,
    contamination=0.135,
    max_samples="auto",
    max_features=7,
    random_state=15
)

iso.fit(FEATS, Y)

y_pred = iso.predict(FEATS)

# Também pode pegar uma "pontuação de anomalia": quanto menor, mais anômalo
scores = iso.decision_function(FEATS)

plt.figure(figsize=(12, 6))

# Plota a linha do valor real
plt.plot(Y, label="Real (machine_status)", color="red", linestyle="-")

# Plota a linha da previsão
plt.plot(y_pred, label="Previsto (Isolation Forest)", color="yellow", linestyle="--")

plt.xlabel("Índice das instâncias")
plt.ylabel("Status (1 = NORMAL, -1 = ANOMALIA)")
plt.title("Comparação Real vs Previsto")
plt.legend()
plt.ylim(-1.5, 1.5)
plt.grid(True)

plt.show()

# calcula a matriz de confusão
cm = confusion_matrix(Y, y_pred, labels=[1, -1])  # ajuste os labels conforme suas classes

# plot usando seaborn
plt.figure(figsize=(6, 5))
sns.heatmap(cm, annot=True, fmt="d", cmap="Blues", xticklabels=["NORMAL Previsto", "RECOVERING Previsto"], yticklabels=["NORMAL Real", "RECOVERING Real"])
plt.xlabel("Previsão")
plt.ylabel("Real")
plt.title("Matriz de Confusão")
plt.show()

print(classification_report(Y, y_pred, labels=[1, -1]))