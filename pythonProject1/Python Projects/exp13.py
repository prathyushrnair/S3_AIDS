# 12 Plot a graph y = f(x)
import matplotlib.pyplot as pt

continents = ['Africa', 'Asia', 'Europe', 'North America', 'Oceania', 'South America', 'Soviet Union']
areas = [11.7, 10.4, 1.9, 9.4, 3.3, 6.9, 7.9]
pt.figure(figsize=(10, 10))
pt.bar(continents,areas,color="black")
pt.title("Continents with area on mill of sq miles [MERICA ]")
pt.xlabel("continents")
pt.ylabel("Areas in millions of sq miless")
pt.grid(axis='y',linestyle='--',alpha=0.7)
pt.tight_layout()

pt.show()
