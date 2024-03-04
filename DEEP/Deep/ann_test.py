import pandas as pd

#Loading Dataset
data = pd.read_csv("C:\FUN ZONE\CODE\ML\Deep\Data\Churn_Modelling.csv")
X = data.iloc[:,3:-1].values
Y = data.iloc[:,-1].values
print(Y)