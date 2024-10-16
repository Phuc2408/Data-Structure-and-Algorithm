#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string song;
    Node *next;
    Node *prev;

    Node(string songName)
    {
        song = songName;
        next = nullptr;
        prev = nullptr;
    }
};

class MusicPlayer
{
private:
    Node *head;
    Node *tail;
    Node *current;
    int totalSongs;

public:
    MusicPlayer()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        totalSongs = 0;
    }

    void addSong(string songName)
    {
        Node *newNode = new Node(songName);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
            current = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
        totalSongs++;
    }

    void playNext()
    {
        if (current != nullptr)
        {
            current = current->next; // Move to the next song
        }
    }

    void playPrev()
    {
        if (current != nullptr)
        {
            current = current->prev; // Move to the previous song
        }
    }

    void removeSong(string songName)
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        do
        {
            if (temp->song == songName)
            {
                if (temp == head && temp == tail)
                {
                    delete temp;
                    head = tail = current = nullptr;
                }
                else if (temp == head)
                {
                    head = head->next;
                    tail->next = head;
                    head->prev = tail;
                    if (current == temp)
                        current = head;
                    delete temp;
                }
                else if (temp == tail)
                {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                    if (current == temp)
                        current = tail;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (current == temp)
                        current = temp->next; // Update current if removed
                    delete temp;
                }
                totalSongs--;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    // Method to display the playlist and return the output string
    string displayPlaylist()
    {
        string output; // Store output as a string
        if (head == nullptr)
        {
            output = "Playlist is empty";
            return output;
        }

        Node *temp = head;
        do
        {
            output += temp->song + " "; // Add songs to the output string
            temp = temp->next;
        } while (temp != head);

        return output; // Return the output string
    }
};

int main()
{
    int n;
    cin >> n;

    MusicPlayer player;
    string outputs; // String to store all outputs

    for (int i = 0; i < n; ++i)
    {
        string command;
        cin >> command;

        if (command == "ADD")
        {
            string songName;
            cin.ignore();
            getline(cin, songName);
            player.addSong(songName);
        }
        else if (command == "NEXT")
        {
            player.playNext();
        }
        else if (command == "PREV")
        {
            player.playPrev();
        }
        else if (command == "REMOVE")
        {
            string songName;
            cin.ignore();
            getline(cin, songName);
            player.removeSong(songName);
        }
        else if (command == "DISPLAY")
        {
            string currentPlaylist = player.displayPlaylist(); // Get current playlist
            outputs += currentPlaylist + "\n";                 // Append the result to outputs
        }
    }

    cout << "Output: " << endl;
    cout << outputs; // Print all outputs at once
    system("pause");
    return 0;
}
