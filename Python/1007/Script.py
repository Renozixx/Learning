import pandas as pd
from sklearn.pipeline import Pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import MinMaxScaler
from sklearn.feature_selection import SelectKBest, f_regression
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor, GradientBoostingRegressor
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score
import numpy as np

# data = pd.read_csv('household_power_consumption.csv') # Luis
data = pd.read_csv('Python\\1007\\household_power_consumption.csv', index_col=None) # Vinicius

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

#Retirando a info de qual algoritmo será melhor para o nosso problema

randomForest = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),       
    ('scaler', MinMaxScaler()),                        
    ('selector', SelectKBest(score_func=f_regression, k=4)),  
    ('model', RandomForestRegressor(random_state=42))
])

linearRegression = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),
    ('scaler', MinMaxScaler()),
    ('selector', SelectKBest(score_func=f_regression, k=4)),
    ('model', LinearRegression())
])

gradientBoost = Pipeline([
    ('imputer', SimpleImputer(strategy='mean')),
    ('scaler', MinMaxScaler()),
    ('selector', SelectKBest(score_func=f_regression, k=4)),
    ('model', GradientBoostingRegressor(
    n_estimators=100,     # número de árvores
    learning_rate=0.1,    # taxa de aprendizado
    max_depth=3,          # profundidade das árvores (indiretamente, via base_estimator)
    random_state=42))
])

randomForest.fit(X_train, y_train)
y_randomForest = randomForest.predict(X_test)

linearRegression.fit(X_train, y_train)
y_linearRegression = linearRegression.predict(X_test)

gradientBoost.fit(X_train, y_train)
y_gradientBoost = gradientBoost.predict(X_test)

mae_rf = mean_absolute_error(y_test, y_randomForest)
rmse_rf = np.sqrt(mean_squared_error(y_test, y_randomForest))
r2_rf = r2_score(y_test, y_randomForest)

mae_lr = mean_absolute_error(y_test, y_linearRegression)
rmse_lr = np.sqrt(mean_squared_error(y_test, y_linearRegression))
r2_lr = r2_score(y_test, y_linearRegression)

mae_gb = mean_absolute_error(y_test, y_gradientBoost)
rmse_gb = np.sqrt(mean_squared_error(y_test, y_gradientBoost))
r2_gb = r2_score(y_test, y_gradientBoost)

# RMSE -> Quanto menor melhor
# MAE -> Quanto menor melhor
# R² -> Quanto maior melhor, limite em 1

print(f"Random Forest - MAE: {mae_rf:.4f}")
print(f"Random Forest - RMSE: {rmse_rf:.4f}")
print(f"Random Forest - R²: {r2_rf:.4f}")

print(f"Linear Regression - MAE: {mae_lr:.4f}")
print(f"Linear Regression - RMSE: {rmse_lr:.4f}")
print(f"Linear Regression - R²: {r2_lr:.4f}")

print(f"Gradient Boosting Regressor - MAE: {mae_gb:.4f}")
print(f"Gradient Boosting Regressor - RMSE: {rmse_gb:.4f}")
print(f"Gradient Boosting Regressor - R²: {r2_gb:.4f}")


myPipeline = randomForest

prev1 = randomForest.predict([
    [4, 0.502, 233.740, 23.000, 0.000, 1.000, 17.000],
    [4, 0.502, 233.740, 18.000, 0.000, 1.000, 17.000],
    [4, 0.502, 233.740, 13.000, 0.000, 1.000, 17.000]
])

prev2 = gradientBoost.predict([
    [4, 0.502, 233.740, 23.000, 0.000, 1.000, 17.000],
    [4, 0.502, 233.740, 18.000, 0.000, 1.000, 17.000],
    [4, 0.502, 233.740, 13.000, 0.000, 1.000, 17.000]
])

print(prev1, prev2)