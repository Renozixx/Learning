import pandas as pd
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers
import matplotlib.pyplot as plt

# Leitura do dataset
ds = pd.read_csv('Walmart_Sales.csv')

# Separando as variaveis que queremos prever, e tratando nosso arquivo
y = ds['Weekly_Sales']
X = ds.drop('Weekly_Sales', axis=1)
X = X.drop('Date', axis=1)

# Dividindo os tipos de coluna
coluna_numerica = ['Temperature', 'Fuel_Price','CPI','Unemployment']
coluna_categorica = ['Store', 'Holiday_Flag']

# Aplicando One-Hot (Transforma valores "flag" em tabelas prontas)
X = pd.get_dummies(X, columns = coluna_categorica, drop_first = True)

# Aplicando a escala no dataset
aply_scale = StandardScaler()
X[coluna_numerica] = aply_scale.fit_transform(X[coluna_numerica])

# Divisão de dados para teste e treino
X_treino, X_teste, y_treino, y_teste = train_test_split(X, y, test_size=0.2, random_state=42)

rn = keras.Sequential([
    layers.Dense(units=128, activation='relu', input_shape=[X_treino.shape[1]]),
    
    layers.Dense(units=64, activation='relu'),

    layers.Dense(units=1)
])

rn.compile(optimizer='adam', loss='mean_squared_error')

result = rn.fit(
    X_treino,
    y_treino,
    epochs = 100,
    validation_split=0.2
)

loss_teste = rn.evaluate(X_teste, y_teste)
print(f'Erro Quadrático Médio (MSE) no conjunto de teste: {loss_teste:.2f}')

plt.figure(figsize=(10, 6))
plt.plot(result.history['loss'], label='Erro de Treino')
plt.plot(result.history['val_loss'], label='Erro de Validação')
plt.title('Curva de Aprendizagem (Loss)')
plt.xlabel('Época')
plt.ylabel('Erro Quadrático Médio (MSE)')
plt.legend()
plt.grid(True)
plt.show()