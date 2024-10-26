Web Scraper Project

This project is a web scraper that uses both C and Python to efficiently retrieve and filter data from multiple URLs. The program takes a list of URLs and a set of keywords to filter content, providing flexibility and scalability in web scraping.

Project Structure

C Modules: Handles the core functionality, including fetching content from URLs and managing basic filtering.
Python Module: Utilizes Python’s libraries for advanced text processing and filtering based on keywords, expanding the functionality of the core C components.

Directory Structure

plaintext
Copy code
web_scraper/
├── input/
│   └── urls.json                 # JSON file containing URLs and keywords
├── python/
│   ├── parser.py                 # Python script for keyword filtering
│   └── requirements.txt          # Lists required Python libraries
└── src/
    ├── main.c                    # Main program in C
    ├── scraper.c                 # C code for scraping functions
    ├── scraper.h                 # Header file for scraper.c
    ├── utils.c                   # Utility functions
    └── utils.h                   # Header file for utils.c
Usage

Compile the C code:

gcc src/main.c src/scraper.c src/utils.c -o webscraper -lcurl -lcjson

Install Python dependencies:

pip install -r python/requirements.txt

Run the program:

./webscraper

The program reads from input/urls.json to get the list of URLs and keywords for filtering.

Libraries Used

C Libraries
libcurl: Manages HTTP requests, allowing the program to retrieve data from specified URLs.
cJSON: Parses JSON configuration files, making it easy to manage URL and keyword input.
Python Libraries
requests: Facilitates additional HTTP requests (if needed for expansion).
BeautifulSoup: Parses HTML content, making it easier to identify and filter information.
re (Regex): Assists in complex text filtering for identifying keyword matches.
Upcoming Features

The following improvements are planned:

Error Handling Enhancements (C Module):
Add more robust error handling in scraper.c to handle network timeouts, invalid URLs, etc.
Improved Filtering Logic (Python Module):
Modify parser.py to support complex keyword searches using regex patterns and case insensitivity.
Multi-threading:
Implement multi-threading in main.c to allow for concurrent URL scraping, which will significantly improve performance.
Output Formatting:
Enable saving filtered content in various formats (e.g., JSON, CSV), making the scraper more versatile.
