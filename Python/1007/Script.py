import pandas as pd
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import MinMaxScaler
from sklearn.feature_selection import SelectKBest, f_regression
from sklearn.ensemble import RandomForestRegressor
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error
import numpy as np

data = pd.read_csv('household_power_consumption.csv')

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
target_column = 'Global_active_power'
features = [col for col in data.columns if col not in ['Date', target_column] and data[col].dtype != 'object']

X = data[features]
y = data[target_column]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, shuffle=False) # Use shuffle=False para manter a ordem temporal

print("Total de Colunas em X:", X.shape[1])
print("Tipos de Dados em X:")
print(X.dtypes)

for col in cols_object:
    data[col] = pd.to_numeric(data[col], errors='coerce')

print(data)
# Encerrando o pré processamento

correlation = data.corr(numeric_only=True)
print(correlation)
print(data.dtypes)

plt.figure(figsize=(10, 8))
sns.heatmap(correlation, annot=True, cmap='coolwarm')
plt.title('Matriz de Correlação')
plt.show()

myPipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),       
    ('scaler', MinMaxScaler()),                        
    ('selector', SelectKBest(score_func=f_regression)),  
    ('model', RandomForestRegressor(random_state=42))
])
myPipeline.set_params(selector__k=5)

myPipeline.fit(X_train, y_train)
y_pred_rf = myPipeline.predict(X_test)

mae_rf = mean_absolute_error(y_test, y_pred_rf)
rmse_rf = np.sqrt(mean_squared_error(y_test, y_pred_rf))

print(f"Random Forest - MAE: {mae_rf:.4f}")
print(f"Random Forest - RMSE: {rmse_rf:.4f}")

