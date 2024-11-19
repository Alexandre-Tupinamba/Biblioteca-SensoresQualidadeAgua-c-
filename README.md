
# Biblioteca para leitura dos sensores
![image](https://github.com/user-attachments/assets/edb66beb-5780-4bf2-b420-d22b369dcaca)



Repositório para o desenvolvimento de bibliotecas e exemplos voltados ao monitoramento remoto da qualidade da água nos rios amazônicos, utilizando sensores integrados ao **Arduino**. 

## Introdução

Este repositório contém:

- **Bibliotecas personalizadas** para sensores de qualidade da água.
- **Exemplos práticos** para utilização com Arduino.
- **Documentação e tutoriais** para auxiliar no uso dos sensores.

### Sensores suportados:

- **TDS** (Total Dissolved Solids) para medir sólidos dissolvidos.
- **Turbidez** para avaliar partículas em suspensão na água.
- **pH** para medir a acidez ou alcalinidade.
- **Temperatura** para monitoramento térmico.


## Instalação

Você pode instalar as bibliotecas de diferentes maneiras. Abaixo estão alguns métodos:

### Método 1: Clonar o Repositório

1. Clone o repositório:
   ```bash
   git clone https://github.com/Lab-IoT-Ufam/Biblioteca-SensoresQualidadeAgua-c-.git
   ```

2. Caso não tenha o Git instalado:
   ```bash
   sudo apt install git
   ```

3. Adicione as bibliotecas:
   - Copie as pastas das bibliotecas para o diretório `libraries` da IDE Arduino.

4. Configure os sensores:
   - Escolha o exemplo correspondente ao sensor desejado.
   - Siga as instruções do código para conexão e calibração.

---

### Método 2: Importar Biblioteca ZIP na IDE Arduino

1. **Baixe o repositório como ZIP:**
   - Acesse o repositório no GitHub.
   - Clique em `Code` e depois em `Download ZIP`.
   ![image](https://github.com/user-attachments/assets/3a90f8f6-3a0e-4e07-a5df-79df570c7781)


2. **Abra a IDE Arduino.**

3. **Importe a biblioteca:**
   - Vá em `Sketch > Incluir Biblioteca > Adicionar Biblioteca .ZIP...`.
   - Selecione o arquivo ZIP que você baixou.
     ![image](https://github.com/user-attachments/assets/ed9578d0-7599-4c4c-ac74-9f9516404c6c)


4. Reinicie a IDE Arduino (se necessário).

---

### Método 3: Usando o Gerenciador de Bibliotecas

1. Abra a IDE Arduino.

2. **Abra o Gerenciador de Bibliotecas:**
   - Vá em `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...`.

3. **Procure pela biblioteca:**
   - No campo de busca, digite o nome da biblioteca.

4. **Instale a biblioteca:**
   - Selecione a biblioteca na lista e clique em `Instalar`.

5. Aguarde a instalação e feche o gerenciador.

---

### Método 4: Instalação Manual

1. **Baixe a biblioteca:**
   - Navegue até a pasta da biblioteca específica no GitHub.
   - Baixe apenas a pasta da biblioteca desejada.

2. **Copie para o diretório de bibliotecas:**
   - Coloque a pasta da biblioteca em:
     - **Windows**: `Documentos\Arduino\libraries`
     - **macOS**: `Documentos/Arduino/libraries`
     - **Linux**: `~/Arduino/libraries`

3. Reinicie a IDE Arduino (se necessário).

---

## Configuração dos Sensores

Após instalar as bibliotecas:

1. Escolha o exemplo correspondente ao sensor desejado.
2. Conecte os sensores conforme as instruções nos comentários do código.
3. Calibre os sensores, se necessário, seguindo as orientações nos exemplos.

---

## Exemplos de Código

### 1. **TemperatureSensor.pde**

- **Descrição**: Mede a temperatura ambiente utilizando o sensor conectado à porta analógica A0.
- **Uso principal**: Monitoramento térmico.
- **Exemplo de saída**:
  ```
  Temperatura no Sensor é: 25°C
  ```
- **Código exemplo**:
  ```cpp
  #include <Temperatura.h>
  temperatura temp(A0); // Inicializa o sensor

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    int temperatura = temp.PegaValorTemp(); // Obtém a temperatura
    Serial.print("Temperatura no Sensor é: ");
    Serial.print(temperatura);
    Serial.println("°C");
    delay(1000);
  }
  ```

---

### 2. **sensoresUnificadosNovo.ino**

- **Descrição**: Código unificado que lê valores de todos os sensores (temperatura, TDS, pH e turbidez).
- **Uso principal**: Monitoramento completo em um único programa.
- **Exemplo de saída**:
  ```
  Temperatura: 25°C
  TDS: 300 ppm
  pH: 7.0
  Turbidez: 1.2 NTU
  ```
- **Código exemplo**:
  ```cpp
  #include <Temperatura.h>
  #include <GravityTDS.h>
  #include <phSensor.h>
  #include <Turbidez.h>

  temperatura tempSensor(A0);
  GravityTDS gravityTds;
  phSensor ph(A1);
  turbidezSensor turbidez(A2);

  void setup() {
    Serial.begin(9600);
    gravityTds.setPin(A3);
    gravityTds.begin();
  }

  void loop() {
    lerValorTemp();
    lerValorTDS();
    lerValorPh();
    lerValorTurbidez();
    delay(1000);
  }
  ```

---

### 3. **ValorTurbidez.ino**

- **Descrição**: Mede e exibe os valores médios de turbidez e a voltagem correspondente.
- **Uso principal**: Avaliação de partículas em suspensão.
- **Código exemplo**:
  ```cpp
  #include <Turbidez.h>

  turbidezSensor turbidez(A1);

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    float valor = turbidez.pegaValorTurbidezMedia();
    float voltagem = turbidez.pegaValorVoltagem();

    Serial.print("Turbidez: ");
    Serial.print(valor);
    Serial.println(" NTU");

    Serial.print("Voltagem: ");
    Serial.print(voltagem);
    Serial.println(" V");

    delay(1000);
  }
  ```
---

### 4. **GravityTDSExample.ino**

- **Descrição**: Mede os valores de TDS (Total Dissolved Solids) em ppm e permite calibração.
- **Uso principal**: Monitoramento de sólidos dissolvidos.
- **Exemplo de saída**:
  ```
  TDS: 300 ppm
  ```
- **Código exemplo**:
  ```cpp
  #include <GravityTDS.h>

  GravityTDS gravityTds;

  void setup() {
    Serial.begin(9600);
    gravityTds.setPin(A2);
    gravityTds.setAref(5.0);
    gravityTds.setAdcRange(1024);
    gravityTds.begin();
  }

  void loop() {
    gravityTds.setTemperature(25);
    gravityTds.update();
    float tdsValue = gravityTds.getTdsValue();

    Serial.print("TDS: ");
    Serial.print(tdsValue);
    Serial.println(" ppm");

    delay(1000);
  }
  ```

---

### 5. **PegaValorPh.ino**

- **Descrição**: Mede o pH da água utilizando múltiplas leituras para maior precisão.
- **Uso principal**: Monitoramento da acidez ou alcalinidade da água.
- **Exemplo de saída**:
  ```
  pH: 7.0
  ```
- **Código exemplo**:
  ```cpp
  #include <phSensor.h>

  phSensor ph(A3);

  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    float valor = ph.pegaValorPhMedia(13);

    Serial.print("pH: ");
    Serial.println(valor);

    delay(1000);
  }
  ```

---


## Documentação e Tutoriais

Links para guias e documentação detalhada:

- [Sensor de TDS: Projeto Medidor de TDS para Condutividade de Água](https://www.usinainfo.com.br/blog/projeto-medidor-de-tds-arduino-para-condutividade-da-agua/)
- [Sensor de Turbidez: Leitura da Qualidade da Água](https://www.usinainfo.com.br/blog/sensor-de-turbidez-projeto-de-leitura-da-qualidade-da-agua/)
- [Sensor de pH: Calibração e Configuração](https://www.usinainfo.com.br/blog/sensor-de-ph-arduino-como-calibrar-e-configurar/)
- [Sensor de Temperatura: Montagem e Explicação](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-sensor-de-temperatura-ntc-10k-3950-prova-dagua-do-tipo-sonda)

---

