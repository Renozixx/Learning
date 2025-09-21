# Utilizando KNN 
import pandas as pd
import numpy as np
import math
import matplotlib.pyplot as plt
from sklearn.neighbors import KNeighborsClassifier

def euclidianCount(p, q):
    return math.sqrt(pow((p[0] - q[0]), 2) + pow((p[1] - q[1]),2))
    
def manhatamCount(p, q):
    return abs(p[0] - q[0]) + abs(p[1] - q[1])
    
df = pd.read_csv("Iris.csv")

k = int(input(''))
point = list(map(float, input('').split())) # Ponto para comparar


print("1 - Euclidiana \n2 - Manhatam")
mode = int(input(''))

metric = 'euclidean' if mode == 1 else 'manhattan'

if mode != 1 and mode != 2:
    print("Modo invalido")


pontos = list()
distances = list()
count = 0
ind = 0
maxi = 0
for i,r in df.iterrows():
    dist = euclidianCount([r.SepalLengthCm, r.SepalWidthCm], point) if mode == 1 else manhatamCount([r.SepalLengthCm, r.SepalWidthCm], point)
    if count == k:
        if dist < maxi:
            pontos[ind] = [r.SepalLengthCm, r.SepalWidthCm, r.Species]
            distances[ind] = dist
            maxi = max(distances)
            ind = distances.index(maxi)
    else:        
        count+=1
        distances.append(dist)
        pontos.append([r.SepalLengthCm, r.SepalWidthCm, r.Species])
        maxi = max(distances)
        ind = distances.index(maxi)


counters = list()
models = list()
for i in pontos:
    if i[2] not in models:
        models.append(i[2])
        counters.append(1)
    else:
        ind = models.index(i[2])
        counters[ind] += 1
j = 0
for i in models:
    print(i,":", counters[j])
    j+=1
    
maxi = counters.index(max(counters))
specie = models[maxi]

dataframe = df[['SepalLengthCm','SepalWidthCm','Species']]

teste = {
    'SepalLengthCm': point[0],
    'SepalWidthCm': point[1],
    'Species': specie
}

dataframe = pd.concat([dataframe, pd.DataFrame([teste])], ignore_index=True)
print(dataframe)

# Teste de precisao 
X = df[['SepalLengthCm', 'SepalWidthCm']].values
y = df['Species'].values

# --- Criando e treinando o KNN do sklearn ---
knn = KNeighborsClassifier(n_neighbors=k, metric=metric)
knn.fit(X, y)

# --- Predizendo a espécie do ponto ---
predicted_species = knn.predict([point])[0]

print(f"\nEspécie prevista pelo sklearn para o ponto {point}: {predicted_species}")
print(f"\nEspécie identificada {point}: {specie}")

color_map = {
    'Iris-setosa': 'red',
    'Iris-versicolor': 'green',
    'Iris-virginica': 'blue'
}

dataframe['color'] = dataframe['Species'].map(color_map).fillna('black')


dataframe.plot(
    kind="scatter",
    x="SepalLengthCm",
    y="SepalWidthCm",
    c=dataframe["color"].tolist(), 
    cmap="Set1",
    s=80,
    alpha=0.8,
    colorbar=True
)

plt.title("Iris Dataset - SepalLength vs SepalWidth")
plt.show()