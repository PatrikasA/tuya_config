#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "cJSON.h"
#include "tuya_cacert.h"
#include "tuya_log.h"
#include "tuya_error_code.h"
#include "system_interface.h"
#include "mqtt_client_interface.h"
#include "tuyalink_core.h"

const char productId[] = "iikoumndniwcibgi";
const char deviceId[] = "26472e385f87e96e2alyjm";
const char deviceSecret[] = "e62c9057d7197d30";

tuya_mqtt_context_t client_instance;

void on_connected(tuya_mqtt_context_t* context, void* user_data)
{
    TY_LOGI("on connected");
    tuyalink_subdevice_bind(context, "[{\"productId\":\"xankwfjqkkhd0dct\",\"nodeId\":\"123455\",\"clientId\":\"123455asdf\"}]");
    tuyalink_subdevice_topo_get(context);
}

void on_disconnect(tuya_mqtt_context_t* context, void* user_data)
{
    TY_LOGI("on disconnect");
}

void on_messages(tuya_mqtt_context_t* context, void* user_data, const tuyalink_message_t* msg)
{
    // tuyalink_message_t* msg;    msg->data_json verte visada bus null. Json'as yra patalpintas string formatu msg->data_string
    // taip pat, prisijungimo prie serverio metu bus grazintas null json'as
    // bent ta parode (ribotas) testavimas
    TY_LOGI("on message id:%s, type:%d, code:%d", msg->msgid, msg->type, msg->code);
    cJSON *json = NULL;
    if (msg->data_string != NULL) {
	    json = cJSON_Parse(msg->data_string);
	    if (json != NULL) {
		    cJSON *value = cJSON_GetObjectItemCaseSensitive(json, "asd");
            if(value != NULL)
	            printf("THE VALUE IS: %s\n", value->valuestring);
	    }
    }

    switch (msg->type) {
    case THING_TYPE_DEVICE_SUB_BIND_RSP:
            TY_LOGI("bind response:%s\r\n", msg->data_string);
            break;

        case THING_TYPE_DEVICE_TOPO_GET_RSP:
            TY_LOGI("get topo response:%s\r\n", msg->data_string);
            break;

        default:
            break;
	}
    printf("\r\n");
}

int main(int argc, char** argv)
{
    int ret = OPRT_OK;

    tuya_mqtt_context_t* client = &client_instance;

    ret = tuya_mqtt_init(client, &(const tuya_mqtt_config_t) {
        .host = "m1.tuyacn.com",
        .port = 8883,
        .cacert = tuya_cacert_pem,
        .cacert_len = sizeof(tuya_cacert_pem),
        .device_id = deviceId,
        .device_secret = deviceSecret,
        .keepalive = 100,
        .timeout_ms = 2000,
        .on_connected = on_connected,
        .on_disconnect = on_disconnect,
        .on_messages = on_messages
    });
    assert(ret == OPRT_OK);

    ret = tuya_mqtt_connect(client);
    assert(ret == OPRT_OK);


    for (;;) {
	    tuya_mqtt_loop(client);
	    /* Jei JSON key sutampa su device'o funkcija, kuri yra sukurta per web'o UI, pranešimai nebus rašomi į logą.
        Gali būti, kad tą funkciją reikia pakonfigūruoti, kad log'ai būtų rašomi.*/
	    //tuyalink_thing_property_report_with_ack(client, NULL,
		//				    "{\"asde\":{\"value\":\"asd\",\"time\":1631708204231}}");
	    //sleep(2);
    }

    return ret;
}
