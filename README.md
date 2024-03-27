# Automação Aquário

  Introdução: dentro do mundo do aquarismo, existem os chamados aquários plantados, que são montados com fauna e flora que necessitam de parâmetros em condições similares e estáveis. Alguns desses parâmetros são: temperatura, pH, iluminação, entre outros. Dessa forma, para a manutenção desses parâmetros é necessário realizar um monitoramento e controle dessas variáveis, corriqueiramente. Assim, com esse projeto, tem-se o objetivo de implementar um sistema que permita monitorar os parâmetros de um aquário, e controlá-los de forma remota, a partir de acesso à internet. Permintindo, assim, facilitar a manutenção do aquário, a partir de sua automação.

  Objetivo do projeto: realizar a automação de um aquário para o monitoramento e controle de parâmetros de forma remota, tais como: temperatura da água, alimentação dos peixes, iluminação. Além de permitir, a realização de TPA (troca de água parcial) da água do aquário, para normalização dos parâmetros, de forma manual (remota) ou automática.
  
  Detalhamento do projeto: para a obtenção de dados e controle de parâmetros serão utilizados sensores: temperatura e luminosidade. Para o controle da alimentação dos peixes será utilizado um motor de passo. Para a atuação sobre a temperatura do aquário, será utilizado um aquecedor e uma ventoinha. Para a realização da troca de água, serão utilizadas duas bombas: uma que fará a retirada da água do aquário, e a segunda, que irá injetar água tratada no aquário, a partir de um reservatório externo. Como unidade controlodora, será utilizada uma ESP32. Para a disposição dos dados do projeto, e o controle remoto de parâmetros, será utilizado a plataforma Arduino Iot Cloud, com acesso no aplicativo no smartphone, com conexão à internet.

  Componentes: 
- ESP32
- 1 Sensor de temperatura DS18B20
- 1 Sensor de luminosidade LDR
- 2 Bombas de água
- 1 Motor de passo
- 4 Relés 
- 1 Lâmpada 
- 1 Aquecedor de água
- 1 Cooler para refrigeração
- Mangueira de silicone
- Smartphone com conexão com a Internet
               
