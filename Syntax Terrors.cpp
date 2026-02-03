#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------------- Utility Functions ----------------
string toLower(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

bool hasWord(string text, string word) {
    return text.find(word) != string::npos;
}

// ---------------- Game Structures ----------------
struct Question {
    string q;
    string options[4];
    int correct;
};

// ---------------- Game Functions ----------------
bool game_quiz() {
    Question quiz[5] = {
        {"Largest planet?", {"Earth","Mars","Jupiter","Venus"}, 3},
        {"Days in a leap year?", {"364","365","366","367"}, 3},
        {"National flower of Pakistan?", {"Rose","Tulip","Lily","Jasmine"}, 4},
        {"Language used to create this program?", {"Python","C++","Java","HTML"}, 2},
        {"What is 5*5?", {"20","25","15","30"}, 2}
    };

    int score = 0, ans;
    for(int i = 0; i < 5; i++) {
        cout << "\n" << quiz[i].q << "\n";
        for(int j = 0; j < 4; j++) 
            cout << j+1 << ". " << quiz[i].options[j] << "\n";
        cout << "Answer (1-4): ";
        while(!(cin >> ans) || ans < 1 || ans > 4) {
            cin.clear(); cin.ignore(10000,'\n');
            cout << "Enter a valid number (1-4): ";
        }
        if(ans == quiz[i].correct) score++;
    }

    cout << "\nScore: " << score << " / 5\n";
    cout << (score>=3 ? "?? You WIN the quiz!\n" : "? You LOSE the quiz.\n");
    return score >= 3;
}


void numberGuessingGame() {
    cout << "\n=== Number Guessing Game ===\n";
    int target = rand() % 100 + 1, guess;
    cout << "I picked a number between 1 and 100. You have 3 tries.\n";

    for(int i=1; i<=3; i++){
        cout << "Try " << i << ": ";
        while(!(cin >> guess)){ cin.clear(); cin.ignore(10000,'\n'); cout << "Enter a valid number: "; }
        if(guess == target){ cout << "?? Correct! You WIN.\n"; return; }
        else if(guess < target) cout << "Too low.\n";
        else cout << "Too high.\n";
    }
    cout << "? Game Over! The number was " << target << ".\n";
}

bool game_dice() {
    cout << "\n=== Dice Guess Game ===\n";
    int dice = rand() % 6 + 1, guess;
    cout << "Guess a number between 1 and 6: ";
    while(!(cin >> guess) || guess<1 || guess>6)
	{
	cin.clear();
	cin.ignore(10000,'\n');
	cout << "Enter 1-6: "; }
    cout << "Dice rolled: " << dice << "\n";
    cout << (guess==dice ? "?? Correct! You WIN.\n" : "? Wrong! You LOSE.\n");
    return guess == dice;
}

string getJoke() {
    string jokes[6] = {
        "Why do programmers prefer dark mode?\nBecause light attracts bugs! ??",
        "Why do Java developers wear glasses?\nBecause they don't C#! ??",
        "I told my code a joke… it didn’t get it and crashed",
        "Programmers don’t get scared of ghosts, only null pointers",
        "Why was the function feeling sad?\nBecause it didn't get called! ??",
        "Why did the programmer quit?\nBecause he didn't get arrays! ??"
    };
    return jokes[rand()%6];
}

void game() {
    int choice;
    cout << "\nChoose a Game:\n1. Quiz\n2. Number Guess\n3. Dice Roll\nChoice (1-3): ";
    while(!(cin >> choice) || choice<1 || choice>3){ cin.clear(); cin.ignore(10000,'\n'); cout << "Enter 1-3: "; }
    cin.ignore();
    if(choice==1) game_quiz();
    else if(choice==2) numberGuessingGame();
    else if(choice==3) game_dice();
    cin.ignore(10000, '\n');

}

// ---------------- Main Chatbot ----------------
int main() {
    srand(time(0));
    string* userName = new string; // pointer usage
    string input;
    int messageCount = 0;

    // Welcome message
    cout << "\n+------------------------------------+\n";
    cout << "¦   ?? AI PROGRAMMING CHATBOT ??       ¦\n";
    cout << "¦  Learn • Chat • Games • Have Fun!    ¦\n";
    cout << "+------------------------------------+\n\n";

    cout << "Bot: Hi! I'm ChatBot built by Syntax Terrors! What's your good name?\nYou: ";
    getline(cin, *userName);
    cout << "\nBot: Nice to meet you, " << *userName << "! ??\n";
    cout << "     I can teach programming, AI, Data Science, tell jokes, or play games.\n";
    cout << "     Type 'help' to see all options.\n";

    // Chat loop
    while(true){
        cout << "\n" << *userName << ": ";
        getline(cin, input);
        string lower = toLower(input);
        messageCount++;

        if(hasWord(lower,"hello") || hasWord(lower,"hi"))
            cout << "Bot: Hey " << *userName << "! ??\n";

        else if(hasWord(lower,"help")){
            cout << "\n+----------------------------------+\n";
            cout << "¦       ?? I CAN HELP WITH:        ¦\n";
            cout << "+----------------------------------¦\n";
            cout << "¦ ?? AI & Machine Learning         ¦\n";
            cout << "¦ ?? Data Science                  ¦\n";
            cout << "¦ ?? Programming Basics            ¦\n";
            cout << "¦ ?? Jokes                         ¦\n";
            cout << "¦ ?? Games                         ¦\n";
            cout << "¦ ?? Say 'bye' to exit             ¦\n";
            cout << "+----------------------------------+\n";
        }

        // Artificial Intelligence
        else if (hasWord(lower, "ai") || hasWord(lower, "artificial intelligence")) {
        cout << "\nBot: AI stands for Artificial Intelligence! ??"<<endl;
        cout << "     AI is all about making computers smart like humans. "<<endl;
        cout << "     It helps machines to think, learn, and make smart choices. "<<endl;
        cout << "     You see AI in many places - like when you talk to Siri or Alexa, "<<endl;
        cout << "     when Netflix suggests movies you might like, or in self-driving cars. "<<endl;
        cout << "     AI works by studying data and finding patterns to get better over time."<<endl;
        }

        // Machine Learning
         else if (hasWord(lower, "machine learning") || hasWord(lower, "ml")) {
            cout << "\nBot: Machine Learning is a cool part of AI! ??";
            cout << "     Machine Learning is like teaching computers to learn by themselves. "<<endl;
            cout << "     Instead of telling the computer every single step, we give it examples. "<<endl;
            cout << "     The computer looks at these examples and learns patterns from them. "<<endl;
            cout << "     This is used in email spam filters, recommendation systems, "<<endl;
            cout << "     face recognition apps, and even medical diagnoses. "<<endl;
            cout << "     The more data it gets, the smarter it becomes!"<<endl;
        }
        
        // Data Science
        else if (hasWord(lower, "data science") || hasWord(lower, "data scientist")) {
            cout << "\nBot: Data Science is super important today! ??\n\n";
            cout << "     Data Science is like being a detective for data. "<<endl;
            cout << "     Imagine you have a huge pile of information - data scientists "<<endl;
            cout << "     are the experts who make sense of it all! ??"<<endl;
            cout << "     Here's what data scientists actually do:"<<endl;
            cout << "     •Collect data from multiple sources, clean and organize it, explore patterns, apply statistical analysis, and present insights using clear visualizations\n\n";
            cout << "     Real-world examples where data science helps:"<<endl;
            cout << "     • Weather forecasting - predicting storms and temperature\n"<<endl;
            cout << "     • Healthcare - analyzing patient data to improve treatments\n"<<endl;
            cout << "     • Business - understanding customer behavior for better marketing\n"<<endl;  
            cout << "     Tools data scientists use:\n"<<endl;
            cout << "     • Python (with libraries like pandas, numpy)\n"<<endl;
            cout << "     • R programming language\n"<<endl;
            cout << "     • SQL for database management\n";
            cout << "     The best part? Data science combines three important skills:\n"<<endl;
            cout << "     ?? Programming + ?? Statistics + ?? Domain Knowledge\n"<<endl;
            cout << "     This makes it a very exciting and valuable career choice!\n"<<endl;
}
        
      //  Programming
        else if (hasWord(lower, "programming") || hasWord(lower, "coding")) {
            cout << "\nBot: Let me explain programming basics! ??\n\n"<<endl;
            cout << "     Programming is giving computers instructions to solve problems. "<<endl;
            cout << "     We write code in languages like Python, Java, or C++.\n\n"<<endl;
            cout << "     Key concepts:\n"<<endl;
            cout << "     • Variables store data\n"<<endl;
            cout << "     • Loops repeat actions\n"<<endl;
            cout << "     • Functions organize code\n"<<endl;
            cout << "     • Conditions make decisions\n\n"<<endl;
            cout << "     It's a useful skill for creating apps, websites, and games!\n"<<endl;
            cout << "     Want to learn about any specific concept?\n"<<endl;
}

        else if (hasWord(lower, "variable")) {
            cout << "\nBot: Variables are like storage boxes! ??\n\n"<<endl;
            cout << "     Think of variables as labeled containers that hold information. "<<endl;
            cout << "     They can store different types of data - numbers, text, or decimals. "<<endl;
            cout << "     Here's how they work:\n\n"<<endl;
            cout << "     int age = 20;        // Stores a whole number\n"<<endl;
            cout << "     string name = \"Ali\";  // Stores text (always in quotes)\n"<<endl;
            cout << "     float price = 99.99; // Stores decimal numbers\n\n"<<endl;
            cout << "     Why use variables? They help remember values, make code readable, "<<endl;
            cout << "     and let you change values easily in one place.\n"<<endl;
        }

         else if (hasWord(lower, "loop")) {
            cout << "\nBot: Loops help avoid repeating code! ??\n\n"<<endl;
            cout << "     Loops let you do the same task many times without writing it again. "<<endl;
            cout << "     There are different types for different situations:\n\n";
            cout << "     FOR loop - Great when you know exactly how many times to repeat:\n"<<endl;
            cout << "     for (int i = 1; i <= 5; i++) {\n";
            cout << "         cout << \"Hello\";  // Prints Hello 5 times\n";
            cout << "     }\n\n";
            cout << "     WHILE loop - Keeps going while a condition is true:\n";
            cout << "     while (hungry == true) {\n";
            cout << "         eatSnack();  // Keeps eating until not hungry\n";
            cout << "     }\n\n";
            cout << "     Loops save time and make code cleaner!\n"<<endl;
        }

        // Functions
        else if (hasWord(lower, "function")) {
            cout << "\nBot: Functions are reusable code packages! ??\n\n"<<endl;
            cout << "     Functions are like mini-programs inside your main program. "<<endl;
            cout << "     You write them once and use them many times. Here's an example:\n\n"<<endl;
            cout << "     int addNumbers(int x, int y) {\n";
            cout << "         return x + y;  // Adds two numbers\n";
            cout << "     }\n\n";
            cout << "     Using the function:\n"<<endl;
            cout << "     int result = addNumbers(5, 3);  // result = 8\n"<<endl;
            cout << "     int another = addNumbers(10, 2); // another = 12\n\n"<<endl;
            cout << "     Benefits: Less code repetition, easier to fix bugs, "<<endl;
            cout << "     and better organization of your program.\n"<<endl;
        }
        

        else if (hasWord(lower, "array")) {
            cout << "\nBot: Arrays store multiple values together! ??\n\n"<<endl;
            cout << "     An array is like a shelf with numbered boxes. "<<endl;
            cout << "     Instead of having 5 separate variables for 5 scores, "<<endl;
            cout << "     you can have one array holding all of them:\n\n"<<endl;
            cout << "     int scores[5] = {90, 85, 92, 78, 88};\n\n"<<endl;
            cout << "     Accessing values:\n"<<endl;
            cout << "     scores[0] = 90  // First box (always starts at 0)\n"<<endl;
            cout << "     scores[2] = 92  // Third box\n"<<endl;
            cout << "     scores[4] = 88  // Last box\n\n"<<endl;
            cout << "     Arrays make it easy to work with lists of similar items.\n"<<endl;
        }

        else if (hasWord(lower, "python")) {
            cout << "\nBot: Python is a great first programming language! ??\n\n"<<endl;
            cout << "     Python is known for being simple and easy to read. "<<endl;
            cout << "     It was created by Guido van Rossum and has become very popular. "<<endl;
            cout << "     People use Python for many things: making websites, analyzing data, "<<endl;
            cout << "     creating games, building AI systems, and automating tasks. "<<endl;
            cout << "     What makes Python special is its clean syntax - it often reads like English. "<<endl;
            cout << "     Plus, there are thousands of free libraries (pre-made tools) available. "<<endl;
            cout << "     It's a friendly language for beginners to start with!\n"<<endl;
        }

        else if(hasWord(lower,"joke") || hasWord(lower,"funny"))
            cout << "\nBot: " << getJoke() << "\n";

        else if(hasWord(lower,"game") || hasWord(lower,"games"))
            game();

        else if(hasWord(lower,"thank"))
            cout << "\nBot: You're welcome, " << *userName << "! ??\n";

         // ------- GOODBYE -------
        else if (hasWord(lower, "bye") || hasWord(lower, "exit")) {
            cout << "\n+------------------------------------+\n";
            cout << "¦     ?? GOODBYE " << userName << "! ??        \n";
            cout << "+------------------------------------+\n\n";
            cout << "?? Chat Summary:\n"<<endl;
            cout << "   Messages: " << messageCount << "\n"<<endl;
            cout << "   Keep learning and coding! ??\n\n"<<endl;
            break;
        }

        else {
            cout << "\nBot: I'm not sure about that. ??\n\n"<<endl;
            cout << "     Try asking about:\n"<<endl;
            cout << "     AI or Machine Learning ??\n"<<endl;
            cout << "     Data Science ??\n"<<endl;
            cout << "     Programming basics (variables, loops, etc.) ??\n"<<endl;
            cout << "     Or say 'joke' for a laugh! ??\n"<<endl;
            cout << "     Or wanna play games? ??\n"<<endl;
            cout << "     Type 'help' to see all topics!\n"<<endl;
        }
    }

    delete userName; 
    return 0;
}

