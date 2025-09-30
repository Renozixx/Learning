import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_diabetes
from sklearn.model_selection import train_test_split, GridSearchCV, learning_curve
from sklearn.pipeline import make_pipeline
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import MinMaxScaler
from sklearn.feature_selection import SelectKBest, f_regression
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, r2_score


diabetes_data = load_diabetes()
X = pd.DataFrame(diabetes_data.data, columns=diabetes_data.feature_names)
y = pd.Series(diabetes_data.target, name="target")


X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

pipeline = make_pipeline(
    SimpleImputer(strategy='median'),
    MinMaxScaler(),
    SelectKBest(score_func=f_regression),
    RandomForestRegressor(random_state=42)
)


param_grid = {
    "selectkbest__k": [5, 7, 9],  # Otimizando o número de features
    "randomforestregressor__n_estimators": [100, 200],
    "randomforestregressor__max_depth": [5, 10, 15],
    "randomforestregressor__min_samples_split": [5, 10],
    "randomforestregressor__min_samples_leaf": [2, 4]
}

grid_search = GridSearchCV(
    estimator=pipeline,
    param_grid=param_grid,
    cv=5,
    scoring='neg_root_mean_squared_error',
    n_jobs=-1,
    verbose=1
)

print("Iniciando a busca por hiperparâmetros...")
grid_search.fit(X_train, y_train)

best_model = grid_search.best_estimator_
print("-" * 75)
print("Melhores parâmetros encontrados:")
print(grid_search.best_params_)
print("-" * 75)

y_predict_train = best_model.predict(X_train)
y_predict_test = best_model.predict(X_test)

print("Avaliando o R²:")
r2_train = r2_score(y_train, y_predict_train)
print(f"R² de Treino: {r2_train:.4f}")
r2_test = r2_score(y_test, y_predict_test)
print(f"R² de Teste:  {r2_test:.4f}")
print("-" * 75)

print("Avaliando o RMSE:")
rmse_train = np.sqrt(mean_squared_error(y_train, y_predict_train))
print(f"RMSE de Treino: {rmse_train:.4f}")
rmse_test = np.sqrt(mean_squared_error(y_test, y_predict_test))
print(f"RMSE de Teste:  {rmse_test:.4f}")
print("-" * 75)

print("Curva de aprendizado...")
train_sizes = np.linspace(0.1, 1.0, 5)

train_sizes, train_scores, test_scores = learning_curve(
    best_model,
    X_train,
    y_train,
    train_sizes=train_sizes,
    cv=5,
    scoring='neg_root_mean_squared_error',
    n_jobs=-1
)

train_scores_mean = -train_scores.mean(axis=1)
test_scores_mean = -test_scores.mean(axis=1)

plt.figure(figsize=(8, 6))
plt.plot(train_sizes, train_scores_mean, label='Erro de Treino', marker='o')
plt.plot(train_sizes, test_scores_mean, label='Erro de Validação', marker='o')
plt.xlabel('Tamanho do Conjunto de Treino')
plt.ylabel('RMSE')
plt.title('Curva do Modelo Otimizado')
plt.legend()
plt.grid(True)
plt.show()