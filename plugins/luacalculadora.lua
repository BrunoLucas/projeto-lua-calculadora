mw = require("wrapper")
l = mw.getFuncoes()

print("lista[1]="..l[1])

 while (i<l.size())
  do
	print("\n Função : %d - %s",i, l[i])
  i = i+1
  end
--print (r)
print("\n...\n")
print("Informe a função :")
numero = io.read()
print("Informe valor 1:")
valor1 = id.read()
print("Informe valor 2:")
valor2 = id.read()
resultaddo = mw.executar(valor1,valor2,numero)
print(resultaddo)



