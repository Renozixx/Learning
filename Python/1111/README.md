# Avaliação Semestral - 

## Orientações Globais -
### 1. Entregáveis e Rubricas
    - Proposta
        * Problema, objetivos, dados, riscos, cronograma, refs iniciais.

    - EDA + Baseline
        Significado - Por meio de um video no youtube vi que o EDA (Exploratory Data Analysis) seria o estudo do 
        dataset selecionado, tal qual quais passos foram feitos por ele até prepara-lo para uso.
        
        * Limpeza, feature engineering inicial, split treino/val.
        * Diagrama de blocos(completo): incluir caminhos de dados, etapas do pré-processamento e ponto de entrada do algoritmo.
    
    - Modelo + Tuning
        * Validação cruzada, learning/validation curves, busca de hiperparâmetros.
        * Explicação detalhada do algoritmo (seção técnica do relatório) contendo:
            ** Intuição e problema de otimização (função de perda/critério).
            ** Principais hiperparâmetros e seus efeitos.
            ** Pseudocódigo (ou fluxograma detalhado).
            ** Complexidade (tempo/memória) e implicações práticas.
            ** Fontes de viés/variância e estratégias de controle.
        * Diagrama de blocos v2: agora incluindo loop de treino/validação e pontos de monitoramento de métricas.

    - Análises
        * Ablations/comparativos, interpretação, fairness/ética.
        * Diagrama final validado (versão publicada no repositório) alinhado ao que foi realmente implementado.

    - Relatório Final + Apresentação (10 min)
        * Resultados, lições, limitações, próximos passos.
        * Slide específico com o diagrama de blocos final.
        * Seção “Como o algoritmo funciona” revisada e coerente com o código.

### 2. Padrões mínimos (será cobrado)
    - Diagrama de blocos (obrigatório):
        * Mostrar o fluxo ponta-a-ponta (dados → preparo → treino → validação → teste → entrega).
        * Indicar transformações (ex.: standardization, TF-IDF, HOG), pontos de decisão (ex.: escolha de k, C, profundidade), loops (CV, early stopping), métricas e artefatos gerados (model.pkl, relatórios).
        * Formatos aceitos: imagem (PNG/SVG), PDF, ou arquivo .drawio / Mermaid (com imagem exportada no relatório).

    - Explicação detalhada do algoritmo (obrigatória):
        * Intuição + formulação (perda/ganho/critério), hipótese do modelo.
        * Hiperparâmetros mais relevantes e seus trade-offs.
        * Pseudocódigo claro, compatível com o diagrama.
        * Complexidade assintótica e implicações de escalabilidade.
        * Riscos de viés/overfitting e mitigações (regularização, validação, amostragem).
        * Limitações conhecidas e quando não usar o algoritmo.

### 3. Pesos 
    1. Diagrama de blocos: 10% (clareza, completude, coerência com o código).
    2. Explicação detalhada: 30% (correção teórica, pseudocódigo, análise de complexidade e limitações).
    3. Aplicação e Resultados 30%
    4. Comunicação 20%
    5. Reprodutibilidade 10%

## Orientações do grupo 

### 9) Anomalias (Isolation Forest / One-Class SVM) — “IoT/sensores”
Grupo: João Mateus, Renó, Luis Ismael
Algoritmos foco: IsolationForest, OneClassSVM.
Aplicação: detecção de anomalias em séries de sensores (energia, vibração, vazão).
Extras: windowing para features temporais, taxa de falsos positivos, interpretação.
Datasets ideias: medidores inteligentes, telemetria, logs operacionais.

### Links Importantes
Canva: https://www.canva.com/design/DAG5cnKZktY/S-MejESpBOAHIVNp1gdsiA/edit?utm_content=DAG5cnKZktY&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton