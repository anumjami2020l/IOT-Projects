#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define led1 D1
#define led2 D2
#define fan1 D4
#define fan2 D5
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Mooazam", "mooazam123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(fan1, OUTPUT);
  pinMode(fan2, OUTPUT);

}

void loop()
{
  // put your main code here, to run repeatedly:
  client = server.available();
  if (client == 1)
  {
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET /led1on HTTP/1.1")
    {
      digitalWrite(led1, HIGH);
      Serial.println("LED 1 is ON");
    }
    if (request == "GET /led1off HTTP/1.1")
    {
      digitalWrite(led1, LOW);
      Serial.println("LED 1 is OFF");
    }
    if (request == "GET /led2on HTTP/1.1")
    {
      digitalWrite(led2, HIGH);
      Serial.println("LED 2 is ON");
    }
    if (request == "GET /led2off HTTP/1.1")
    {
      digitalWrite(led2, LOW);
      Serial.println("LED 2 is OFF");
    }
    if (request == "GET /fan1on HTTP/1.1")
    {
      digitalWrite(fan1, HIGH);
      Serial.println("Fan 1 is ON");
    }
    if (request == "GET /fan1off HTTP/1.1")
    {
      digitalWrite(fan1, LOW);
      Serial.println("Fan 1 is OFF");
    }
    if (request == "GET /fan2on HTTP/1.1")
    {
      digitalWrite(fan2, HIGH);
      Serial.println("FAN 2 is ON");
    }
    if (request == "GET /led2off HTTP/1.1")
    {
      digitalWrite(fan2, LOW);
      Serial.println("FAN 2 is OFF");
    }
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head>");
  client.println("<title>Home automation</title>");
  client.println("</head>");

  client.println("<style>");
  client.println("h1,h2,h3,h4,h5,p{text-align: center;}");
  client.println("*{color: lavender;text-align: center;");
  client.println("background-color: blueviolet;");
  // client.println("*{background-image: url("https://www.mckennaconsultants.com/wp-content/uploads/2020/02/big-data-iot-and-the-cloud.jpg");}");
  client.println("</style>");
  client.println("<body>");
  client.println("<h1>HOME AUTOMATION PROJECT!</h1>");
  client.println(" <h2>IoT  based Project  on home automation  </h2>");
  client.println(" <p>This project based on the IoT in which we automate the home the use of relay NodeMCU and other component</p>");
  client.println(" <h3>ROOM #01</h3>");
  client.println("<strong>LED</strong>");
  client.println("<strong>FAN</strong>");
  client.println("<br>");
  client.println("<a href=\"/led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/led1off\"\"><button>LED 1 OFF</button></a><br/>");
  client.println("<a href=\"/fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/fan1off\"\"><button>FAN  OFF</button></a><br/>");
  client.println("<br>");
  client.println("<h4>ROOM NO # 02</h4>");
  client.println("<strong>LED</strong>");
  client.println("<strong>FAN</strong>");
  client.println("<br>");
  client.println("<a href=\"/led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/led2off\"\"><button>LED 2 OFF</button></a><br/>");
  client.println("<a href=\"/fan2on\"\"><button>FAN 2 ON</button></a>");
  client.println("<a href=\"/fan2off\"\"><button>FAN 2 OFF</button></a><br/>");
  client.println("</body>");

  client.println("</html>");
}
