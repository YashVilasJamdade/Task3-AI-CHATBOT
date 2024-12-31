#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

// Function to convert a string to lowercase
std::string toLower(const std::string& input) {
    std::string lowerCase = input;
    std::transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(), ::tolower);
    return lowerCase;
}

// Sentiment analysis based on keywords
std::string analyzeSentiment(const std::string& userInput) {
    std::vector<std::string> positiveWords = {"happy", "great", "awesome", "good", "fantastic"};
    std::vector<std::string> negativeWords = {"sad", "bad", "terrible", "angry", "upset"};
    
    for (const auto& word : positiveWords) {
        if (userInput.find(word) != std::string::npos) {
            return "You seem happy! 😊";
        }
    }

    for (const auto& word : negativeWords) {
        if (userInput.find(word) != std::string::npos) {
            return "I'm sorry to hear that. 😟 How can I assist you?";
        }
    }

    return "";
}

// Knowledge base with predefined responses
std::unordered_map<std::string, std::string> knowledgeBase = {
    {"what is your name", "I am ChatBot, your virtual assistant!"},
    {"how are you", "I'm just a bunch of code, but I'm here to help you!"},
    {"what can you do", "I can chat with you, answer questions, and provide useful information."},
    {"exit", "Goodbye! Have a great day!"}
};

// Process user input and return a response
std::string processInput(const std::string& userInput) {
    std::string lowerInput = toLower(userInput);

    // Check for sentiment analysis
    std::string sentimentResponse = analyzeSentiment(lowerInput);
    if (!sentimentResponse.empty()) {
        return sentimentResponse;
    }

    // Check the knowledge base for a direct response
    if (knowledgeBase.find(lowerInput) != knowledgeBase.end()) {
        return knowledgeBase[lowerInput];
    }

    // Default fallback response
    return "I'm not sure about that. Can you ask in a different way?";
}

// Main chatbot function
void chatbot() {
    std::cout << "ChatBot: Hi! I'm here to chat with you. Type 'exit' to end the conversation." << std::endl;
    std::string userInput;

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (toLower(userInput) == "exit") {
            std::cout << "ChatBot: " << knowledgeBase["exit"] << std::endl;
            break;
        }

        std::string response = processInput(userInput);
        std::cout << "ChatBot: " << response << std::endl;
    }
}

int main() {
    chatbot();
    return 0;
}
