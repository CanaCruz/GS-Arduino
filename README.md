# 🌊 Sistema de Alerta de Enchentes com Arduino

Este projeto apresenta uma solução funcional e acessível para **monitorar níveis de água** e **emitir alertas** em tempo real, utilizando componentes simples e um Arduino UNO.

## 🚨 Problema

Enchentes urbanas são cada vez mais frequentes e perigosas, causando prejuízos materiais e colocando vidas em risco. Muitos bairros não possuem monitoramento adequado, o que dificulta ações preventivas e emergenciais.

## ✅ Solução

Desenvolvemos um sistema com:

- Sensor ultrassônico para medir o nível da água
- Cálculo automático da porcentagem de enchimento
- LED verde, amarelo, laranja e vermelho indicando o grau de risco
- Buzzer para alerta sonoro em nível crítico
- LCD 16x2 exibindo o nível atual e o pico máximo atingido
- Alternância automática das informações no visor

## 🧠 Lógica de Funcionamento

O sistema calcula o percentual de água com base na profundidade máxima configurada (400 cm). Conforme o valor, aciona:

| Percentual | Ação                         |
|------------|------------------------------|
| 0%–60%     | LED verde - nível seguro     |
| 61%–80%    | LED amarelo - atenção        |
| 81%–89%    | LED laranja - alerta         |
| ≥90%       | LED vermelho + buzzer - perigo |

## 💻 Tecnologias e Componentes

- Arduino Uno
- Sensor ultrassônico HC-SR04
- LCD 16x2 (modo 4 bits)
- LEDs (verde, amarelo, laranja, vermelho)
- Buzzer ativo
- Resistor de 220Ω para cada LED

## 🧪 Simulação

Você pode testar o projeto no simulador **Wokwi** clicando no link abaixo:

🔗 [Simule o Projeto no Wokwi](https://wokwi.com/projects/EXEMPLO-DE-LINK)

## 🖼️ Demonstração

🎥 [Assista ao Vídeo no YouTube](https://youtube.com/EXEMPLO-DE-LINK)

## 🧾 Como Usar

1. Carregue o código no Arduino Uno
2. Conecte os componentes conforme o diagrama
3. Acompanhe o LCD e os LEDs
4. O buzzer soará automaticamente quando o nível ultrapassar 90%

## 📂 Estrutura do Projeto

# GS-Arduino
