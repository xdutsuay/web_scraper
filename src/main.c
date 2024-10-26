#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scraper.h"
#include "utils.h"

#define CONFIG_FILE "../input/urls.json"

// Function to display error messages
void display_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

int main() {
    // Load URLs and keywords from the JSON file
    char **urls;
    char **keywords;
    int url_count, keyword_count;

    // Read the configuration file
    if (read_config_file(CONFIG_FILE, &urls, &url_count, &keywords, &keyword_count) != 0) {
        display_error("Failed to read configuration file.");
        return EXIT_FAILURE;
    }

    // Scrape each URL
    for (int i = 0; i < url_count; i++) {
        printf("Scraping URL: %s\n", urls[i]);
        scrape_url(urls[i], keywords, keyword_count);
    }

    // Free allocated memory
    free(urls);
    free(keywords);

    return EXIT_SUCCESS;
}

