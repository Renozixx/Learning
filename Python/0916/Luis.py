import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.inspection import permutation_importance
from tensorflow import keras
from tensorflow.keras import layers
import matplotlib.pyplot as plt
from tensorflow.keras.callbacks import EarlyStopping
import os

# Leitura do dataset
ds = pd.read_csv('Walmart_Sales.csv')

# Separando as variaveis que queremos prever, e tratando nosso arquivo
y = ds['Weekly_Sales']
X = ds.drop('Weekly_Sales', axis=1)
X = X.drop('Date', axis=1)

# Dividindo os tipos de coluna
coluna_numerica = ['Temperature', 'Fuel_Price', 'CPI', 'Unemployment']
coluna_categorica = ['Store', 'Holiday_Flag']

# Aplicando One-Hot (Transforma valores "flag" em tabelas prontas)
X = pd.get_dummies(X, columns=coluna_categorica, drop_first=True)

# Aplicando a escala no dataset
aply_scale = StandardScaler()
X[coluna_numerica] = aply_scale.fit_transform(X[coluna_numerica])

# Divisão de dados para teste e treino
X_treino, X_teste, y_treino, y_teste = train_test_split(X, y, test_size=0.2, random_state=42)

# Criação da Rede Neural
rn = keras.Sequential([
    # Camada de entrada
    layers.Dense(units=512, activation='relu', input_shape=[X_treino.shape[1]]),
    layers.Dropout(0.2),
    # Camada Oculta
    layers.Dense(units=256, activation='relu'),
    layers.Dropout(0.2),
    # Camada de Saída
    layers.Dense(units=1)
])
# compilação da rede neural
rn.compile(optimizer='adam', loss='mean_squared_error')

early_stopping = EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)
# execução da rede neural
result = rn.fit(
    X_treino,
    y_treino,
    epochs=200,
    validation_split=0.2,
    callbacks=[early_stopping]
)
# Printando o histórico de erros
loss_teste = rn.evaluate(X_teste, y_teste)
print(f'{loss_teste:.2f}')
r = loss_teste **0.5
print(r)

def imp_var(rn, X_teste, y_teste):
    importancia = permutation_importance(
        rn, X_teste, y_teste, n_repeats=10, random_state=42, n_jobs=1,
        scoring='neg_mean_squared_error'
    )
    sorted_importances_idx = importancia.importances_mean.argsort()
    sorted_importances = pd.DataFrame(
        importancia.importances[sorted_importances_idx].T,
        columns=X_teste.columns[sorted_importances_idx],
    )
    print(sorted_importances)

def Testar_rede(X_teste, y_teste, rn):
    # Acessar as duas primeiras linhas do seu conjunto de teste
    dados_para_prever = X_teste.iloc[:2]
    objetivo= y_teste.iloc[:2]

    # Fazer a previsão usando o seu modelo já treinado
    prev = rn.predict(dados_para_prever)

    for i in range(len(prev)):
        print(f"Resultado Alcançado: U${prev[i][0]:,.2f}")
        print(f"Valor Real: U${objetivo.iloc[i]:,.2f}")

        # Calcular e exibir a diferença
        diferenca = prev[i][0] - objetivo.iloc[i]
        print(f"Diferença: U${diferenca:,.2f}")

# plotagem/gráfico
plt.figure(figsize=(10, 6))
plt.plot(result.history['loss'], label='Erro de Treino')
plt.plot(result.history['val_loss'], label='Erro de Validação')
plt.title('Curva de Aprendizagem (Loss)')
plt.xlabel('Época')
plt.ylabel('Erro Quadrático Médio (MSE)')
plt.legend()
plt.grid(True)
plt.show()

Testar_rede(X_teste, y_teste, rn)
imp_var(rn, X_teste, y_teste)
