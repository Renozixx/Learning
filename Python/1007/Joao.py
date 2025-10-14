import pandas as pd # type: ignore
from sklearn.pipeline import Pipeline # type: ignore
from sklearn.impute import SimpleImputer # pyright: ignore[reportMissingModuleSource]
from sklearn.preprocessing import MinMaxScaler # type: ignore
from sklearn.feature_selection import SelectKBest, f_regression # type: ignore
from sklearn.ensemble import RandomForestRegressor # type: ignore
import matplotlib.pyplot as plt # type: ignore
import seaborn as sns # type: ignore
from sklearn.model_selection import train_test_split # type: ignore
from sklearn.metrics import mean_absolute_error, mean_squared_error # type: ignore
import numpy as np # type: ignore

# data = pd.read_csv('household_power_consumption.csv') # Luis
data = pd.read_csv('Python\\1007\\household_power_consumption.csv', sep=';', index_col=None) # Vinicius

print(data)

# Esta parte é so para o pré processamento dos dados

data['Time'], indexes = pd.factorize(data['Time']) # Transformando o Tempo em Indice

# Por um motivo de má leitura dos dados houve uma necessidade em transformar colunas que já deviam ser float em float, so forçar isso mesmo

cols_object = [
    'Global_active_power',
    'Global_reactive_power',
    'Voltage',
    'Global_intensity',
    'Sub_metering_1',
    'Sub_metering_2',
    'Sub_metering_3'
]

for col in cols_object:
    data[col] = pd.to_numeric(data[col], errors='coerce')

data['Global_active_power'] = data['Global_active_power'].fillna(data['Global_active_power'].mean())
print(data)
# Encerrando o pré processamento

correlation = data.corr(numeric_only=True)
print(correlation)
print(data.dtypes)

plt.figure(figsize=(10, 8))
sns.heatmap(correlation, annot=True, cmap='coolwarm')
plt.title('Matriz de Correlação')
plt.show()

target_column = 'Global_active_power'
features = [col for col in data.columns if col not in ['Date', target_column] and data[col].dtype != 'object']

X = data[features]
y = data[target_column]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=False) # Use shuffle=False para manter a ordem temporal

myPipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),
    ('scaler', MinMaxScaler()),
    ('selector', SelectKBest(score_func=f_regression, k=4)),
    ('model', RandomForestRegressor(random_state=42))
])

print(X_train)

myPipeline.fit(X_train, y_train)
y_pred_rf = myPipeline.predict(X_test)

mae_rf = mean_absolute_error(y_test, y_pred_rf)
rmse_rf = np.sqrt(mean_squared_error(y_test, y_pred_rf))

print(f"Random Forest - MAE: {mae_rf:.4f}")
print(f"Random Forest - RMSE: {rmse_rf:.4f}")

# ... (código anterior permanece igual)

# Após as previsões e métricas, adicione:
plt.figure(figsize=(12, 6))

# Plot dos valores reais vs previstos (primeiros 100 pontos para melhor visualização)
plt.plot(y_test.values[:100], label='Valores Reais', color='blue', alpha=0.7)
plt.plot(y_pred_rf[:100], label='Valores Previstos', color='red', alpha=0.7)
plt.title('Comparação: Valores Reais vs Previstos (Random Forest) - Primeiras 100 Amostras')
plt.xlabel('Amostras')
plt.ylabel('Global_active_power')
plt.legend()
plt.grid(True)
plt.show()

# Gráfico de dispersão para comparar previsões vs reais
plt.figure(figsize=(8, 6))
plt.scatter(y_test, y_pred_rf, alpha=0.5)
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'k--', lw=2)
plt.xlabel('Valores Reais')
plt.ylabel('Valores Previstos')
plt.title('Dispersão: Valores Reais vs Previstos')
plt.show()

# Histograma dos erros
errors = y_test - y_pred_rf
plt.figure(figsize=(8, 6))
plt.hist(errors, bins=50, edgecolor='black')
plt.xlabel('Erro de Predição')
plt.ylabel('Frequência')
plt.title('Distribuição dos Erros de Predição')
plt.show()