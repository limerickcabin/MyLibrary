/*
 * posts current status to the IoT Server occasionally and securely
 */
#include <HTTPClient.h>

HTTPClient tideHTTP; 
int postFailures=0;
int httpJSON(String filename, String json);

//returns 0 if successful of appending json to file on server
int httpJSON(String file,String json) {
    int returnCode=0;
    int getCode;
    json.replace("%","%25");
    json.replace(" ","%20");
    //appendJSONS expects secretKey to be correct or the attempt will be ignored
    String url="https://delongiot.com/appendJSONS.php?file="+file+"&row="+json+"&key="+String(secretKey);
    Serial.println("attempting post");
    tideHTTP.begin(url);
    getCode=tideHTTP.GET();
    if (getCode == HTTP_CODE_OK) {
      Serial.println(json+" posted");
    }
    else {
      Serial.printf("POST UNSUCCESSFUL: %d\n",getCode);
      tideHTTP.end();
      tideHTTP.begin(url);
      getCode=tideHTTP.GET();
      if (getCode == HTTP_CODE_OK) {
        Serial.println(json+" posted");
      }
      else {
        Serial.printf("POST UNSUCCESSFUL: %d\n",getCode);
        returnCode=getCode;
      }
    }
    tideHTTP.end();
    if (returnCode==0) postFailures=0;
    else if (++postFailures>10) ESP.restart();
    return(returnCode);
}
