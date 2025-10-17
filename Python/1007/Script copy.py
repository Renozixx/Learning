import pandas as pd
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import MinMaxScaler
from sklearn.feature_selection import SelectKBest, f_regression
from sklearn.ensemble import RandomForestRegressor
import matplotlib.pyplot as plt
import seaborn as sns

data = pd.read_csv('Python\\1007\\household_power_consumption.csv', sep=';', index_col=None)

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
]

for col in cols_object:
    data[col] = pd.to_numeric(data[col], errors='coerce')

print(data)
# Encerrando o pré processamento

# Matrix de correlação
correlation = data.corr(numeric_only=True)
print(correlation)
print(data.dtypes)

plt.figure(figsize=(10, 8))
sns.heatmap(correlation, annot=True, cmap='coolwarm')
plt.title('Matriz de Correlação')
plt.show()
# Acabou a matrix de correlação

target = data['Global_active_power']

features = data.drop(columns=['Global_active_power'])

print(data, target)

myPipeline = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),       
    ('scaler', MinMaxScaler()),                        
    ('selector', SelectKBest(score_func=f_regression)),  
    ('model', RandomForestRegressor(random_state=42))
])

