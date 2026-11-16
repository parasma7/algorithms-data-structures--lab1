/*
Задача № 1
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    // Считываем всю строку целиком, включая пробелы
    getline(cin, s);

    stack<char> st; // Используем стек для отслеживания открывающих скобок
    bool isCorrect = true;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // Если встретили открывающую скобку, кладем её в стек
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            // Если встретили закрывающую скобку, проверяем стек
            if (st.empty()) {
                // Стек пуст, значит закрывать нечего — ошибка
                isCorrect = false;
                break;
            }
            
            char top = st.top();
            st.pop(); // Удаляем верхнюю скобку из стека

            // Проверяем, соответствует ли открывающая скобка закрывающей
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                isCorrect = false;
                break;
            }
        }
    }

    // Если после цикла стек не пуст, значит остались незакрытые скобки
    if (!st.empty()) {
        isCorrect = false;
    }

    // Выводим результат
    if (isCorrect) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}*/

/*Задача № 2*/

/*#include <iostream>
#include <string>
#include <set>
#include <codecvt>
#include <locale>

using namespace std;

int main() {
    string text;
    getline(cin, text);

    wstring_convert<codecvt_utf8<char32_t>, char32_t> cv;
    u32string input = cv.from_bytes(text);
    u32string word;
    set<u32string> words;

    auto addWord = [&]() {
        if (!word.empty()) {
            words.insert(word);
            word.clear();
        }
    };

    for (char32_t c : input) {
        bool latin = (c >= U'A' && c <= U'Z') ||
                     (c >= U'a' && c <= U'z');

        bool russian = (c >= U'А' && c <= U'я') ||
                       c == U'Ё' || c == U'ё';

        if (latin || russian) {
            if (c >= U'A' && c <= U'Z')
                c += 32;
            else if (c >= U'А' && c <= U'Я')
                c += 32;
            else if (c == U'Ё')
                c = U'ё';

            word += c;
        } else {
            addWord();
        }
    }

    addWord();

    cout << "Уникальные слова:\n";

    for (const auto& w : words)
        cout << cv.to_bytes(w) << endl;

    cout << "Всего: " << words.size() << endl;

    return 0;
}*/

/*Задача № 3*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack {
private:
    vector<int> data;
    vector<int> minimums;

public:
    void push(int x) {
        data.push_back(x);

        if (minimums.empty()) {
            minimums.push_back(x);
        } else {
            minimums.push_back(min(x, minimums.back()));
        }
    }

    void pop() {
        if (empty()) {
            cout << "Стек пуст!" << endl;
            return;
        }

        data.pop_back();
        minimums.pop_back();
    }

    bool empty() const {
        return data.empty();
    }

    int getMin() const {
        return minimums.back();
    }
};

int main() {
    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Минимум: " << st.getMin() << endl;

    st.pop();
    cout << "После pop: " << st.getMin() << endl;

    st.pop();
    cout << "После pop: " << st.getMin() << endl;

    st.pop();
    cout << "После pop: " << st.getMin() << endl;

    st.pop();

    cout << "Стек пуст? "
         << (st.empty() ? "Да" : "Нет") << endl;

    return 0;
}


