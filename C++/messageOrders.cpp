/*
https://www.hackerrank.com/challenges/messages-order/problem
*/


class Message {
    string test;
    int seq;
public: 
    Message() {}
    Message(string a, int b){
        test = a;
        seq = b;
    }

    const string& get_text() {
        return test;
    }

    bool operator<(const Message &other) const {
            return seq < other.seq;
    }
};

class MessageFactory {
    int count;
public:
    MessageFactory():count(0) {}
    Message create_message(const string& text) {
        count++;
        return Message(text,count);
    }
};

