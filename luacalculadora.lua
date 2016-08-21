mw = require("wrapper")
l = mw.getFuncoes()
print("tamanho da lista")
print(#l)
if(l == nil) then
 	print ("\nl tem valor nil")
end
print("cheguei aqui")
i=1
 while (i <= #l)
  do
	print("\n Função : %d - %s",(i-1), l[i])
  i = i+1
  end
--print (r)
print("\n...\n")

print("Informe a função  ou 's' para sair:")
numero = io.read()
while (numero ~= 's')
do
print("Informe valor 1:")
valor1 = io.read()
print("Informe valor 2:")
valor2 = io.read()
print("vai chamar a execucao")
resultaddo = mw.executar(valor1,valor2,numero)
print(resultaddo)
print("Informe a função  ou 's' para sair:")

numero = io.read()

end


