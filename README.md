# Projeto de Automação de Aquário

Motivação do Projeto: dentro do mundo do aquarismo, existem os chamados aquários plantados, que são montados com fauna e flora que necessitam de parâmetros em condições similares e estáveis. Alguns desses parâmetros são: temperatura, pH, iluminação, entre outros. Dessa forma, para a manutenção desses parâmetros é necessário realizar um monitoramento e controle dessas variáveis, corriqueiramente. Assim, com esse projeto, tem-se o objetivo de implementar um sistema que permita monitorar os parâmetros de um aquário, e controlá-los de forma remota, a partir de acesso à internet. Permintindo, assim, facilitar a manutenção do aquário, a partir de sua automação.

Objetivo do projeto: realizar a automação de um aquário para o monitoramento e controle de parâmetros de forma remota, tais como: temperatura da água, alimentação dos peixes, iluminação. Além de permitir, a realização de TPA (troca de água parcial) da água do aquário, para normalização dos parâmetros, de forma manual (remota) ou automática.

Componentes: 
- ESP32
- 1 Sensor de temperatura 
- 1 Sensor de luminosidade
- 1 Bomba de água
- 1 Servo motor
- 4 Relés 
- 1 Lâmpada 
- 1 Aquecedor de água
- 1 Cooler para refrigeração
- Mangueira de silicone

Detalhamento do projeto: para a obtenção de dados e controle de parâmetros serão utilizados sensores: temperatura e luminosidade. Para o controle da alimentação dos peixes será utilizado um servo motor. Para a atuação sobre a temperatura do aquário, será utilizado um aquecedor e um cooler para refrigeração. Para a realização da troca de água, será utilizada uma bomba: fará a retirada da água do aquário, ou irá injetar água tratada no aquário, a partir de um reservatório externo. Como unidade controlodora, será utilizada uma ESP32. Para a disposição, de forma visual, dos dados do projeto, e o controle remoto de parâmetros, será utilizada uma dashboard implementada no NodeRED, que irá ser conectada à um broker. O broker utilizado será um broker público da Eclipse IoT. Esse broker será o mesmo ao conectado à ESP32, a qual acessa o broker a partir de conexão Wifi. A partir da figura abaixo, é possível observar em detalhes a arquiterura do projeto.

COLOCAR IMAGEM COM ESQUEMA DA ARQUITETURA DO PROJETO 
(Na Arquitetura é importante que o aluno crie uma figura descritiva, mostrando como cada componentes do projeto interage entre si (dispositivos finais como sensores e atuadores, servidores, roteadores, etc) e protocolos usados na comunicação)
