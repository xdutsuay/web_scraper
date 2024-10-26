#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "cJSON.h"

int read_config_file(const char *filename, char ***urls, int *url_count, char ***keywords, int *keyword_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_string = malloc(length + 1);
    fread(json_string, 1, length, file);
    json_string[length] = '\0';
    fclose(file);

    // Parse JSON
    cJSON *json = cJSON_Parse(json_string);
    if (!json) {
        fprintf(stderr, "JSON parse error: %s\n", cJSON_GetErrorPtr());
        free(json_string);
        return -1;
    }

    // Extract URLs
    cJSON *url_array = cJSON_GetObjectItemCaseSensitive(json, "urls");
    *url_count = cJSON_GetArraySize(url_array);
    *urls = malloc(*url_count * sizeof(char *));
    for (int i = 0; i < *url_count; i++) {
        cJSON *url_item = cJSON_GetArrayItem(url_array, i);
        (*urls)[i] = strdup(url_item->valuestring);
    }

    // Extract keywords
    cJSON *keyword_array = cJSON_GetObjectItemCaseSensitive(json, "keywords");
    *keyword_count = cJSON_GetArraySize(keyword_array);
    *keywords = malloc(*keyword_count * sizeof(char *));
    for (int i = 0; i < *keyword_count; i++) {
        cJSON *keyword_item = cJSON_GetArrayItem(keyword_array, i);
        (*keywords)[i] = strdup(keyword_item->valuestring);
    }

    // Clean up
    cJSON_Delete(json);
    free(json_string);
    return 0;
}

