import sys
from bs4 import BeautifulSoup

def filter_content(html_content, keywords):
    soup = BeautifulSoup(html_content, 'html.parser')
    filtered_texts = []

    # Loop through each keyword and find occurrences in the text
    for keyword in keywords:
        elements = soup.find_all(string=lambda text: text and keyword.lower() in text.lower())
        for element in elements:
            filtered_texts.append(element)

    return filtered_texts

def main():
    if len(sys.argv) != 3:
        print("Usage: python parser.py <html_file> <keywords_file>")
        sys.exit(1)

    html_file = sys.argv[1]
    keywords_file = sys.argv[2]

    # Read HTML content from the file
    with open(html_file, 'r', encoding='utf-8') as f:
        html_content = f.read()

    # Read keywords from the file
    with open(keywords_file, 'r', encoding='utf-8') as f:
        keywords = [line.strip() for line in f.readlines()]

    # Filter content
    filtered_results = filter_content(html_content, keywords)

    # Print the filtered results
    for result in filtered_results:
        print(result)

if __name__ == "__main__":
    main()

