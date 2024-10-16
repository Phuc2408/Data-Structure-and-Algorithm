#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AuthenticationManager
{
private:
    struct Token
    {
        string tokenId;
        int expiryTime;
    };

    Token tokens[100]; // Array to store tokens (limited to 100 tokens)
    int tokenCount;    // Count of current tokens
    int timeToLive;    // Time to live for tokens

public:
    // Constructor: initialize with time to live for tokens
    AuthenticationManager(int ttl)
    {
        timeToLive = ttl;
        tokenCount = 0; // Initialize token count to 0
    }

    // Generate token with ID and current time
    void generate(string tokenId, int currentTime)
    {
        tokens[tokenCount].tokenId = tokenId;
        tokens[tokenCount].expiryTime = currentTime + timeToLive; // Set expiry time
        tokenCount++;
    }

    // Renew token if it hasn't expired
    void renew(string tokenId, int currentTime)
    {
        for (int i = 0; i < tokenCount; ++i)
        {
            if (tokens[i].tokenId == tokenId && tokens[i].expiryTime > currentTime)
            {
                tokens[i].expiryTime = currentTime + timeToLive; // Renew token
                return;
            }
        }
    }

    // Count the number of unexpired tokens at the current time
    int countUnexpiredTokens(int currentTime)
    {
        int count = 0;
        for (int i = 0; i < tokenCount; ++i)
        {
            if (tokens[i].expiryTime > currentTime)
            {
                count++; // Count unexpired tokens
            }
        }
        return count;
    }
};

int main()
{
    int timeToLive;
    cout << "Enter token time to live (TTL): ";
    cin >> timeToLive;

    AuthenticationManager manager(timeToLive);

    int n; // Number of commands
    cout << "Enter number of commands: ";
    cin >> n;

    vector<int> results; // To store results of "count" commands

    for (int i = 0; i < n; ++i)
    {
        string command;
        cin >> command;

        if (command == "generate")
        {
            string tokenId;
            int currentTime;
            cin >> tokenId >> currentTime;
            manager.generate(tokenId, currentTime);
        }
        else if (command == "renew")
        {
            string tokenId;
            int currentTime;
            cin >> tokenId >> currentTime;
            manager.renew(tokenId, currentTime);
        }
        else if (command == "count")
        {
            int currentTime;
            cin >> currentTime;
            results.push_back(manager.countUnexpiredTokens(currentTime)); // Store result
        }
    }

    // Output results after all commands are processed
    cout << "Output:" << endl;
    for (const int &result : results)
    {
        cout << result << endl;
    }

    system("pause");
    return 0;
}
