/**
  Data Node using Arduino and MySQL Database
**/

#include <SPI.h>
#include <Ethernet.h>
#include <sha1.h>
#include <mysql.h>

byte mac_addr[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server_addr(10, 0, 1, 23);

Connector my_conn;

char user[] = "root";
char password[] = "secret";
char INSERT_SQL[] = "INSERT INTO test_arduino.hello VALUES ('Hello!', NULL)";

void setup() {
  Ethernet.begin(mac_addr);
  Serial.begin(115200);
  delay(5000);
  Serial.println("Connecting...");
  if (my_conn.mysql_connect(server_addr, 3306, user, password)) {
    delay(500);
    my_conn.cmd_query(INSERT_SQL);
    Serial.println("Query Success!");
  } else {
    Serial.println("Connection failed.");
  }
}

void loop() {
}
