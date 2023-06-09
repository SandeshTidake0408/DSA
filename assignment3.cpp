// A book consists of chapters, chapters consist of sections and sections consist of subsections. Construct a tree and print the nodes. Find the time and space requirements of your method.

#include <iostream>
#include <string.h>
using namespace std;

class node
{
public:
    string label;
    int ch_count;
    node *child[10];
};

class GT
{
public:
    node *root;
    void create_tree();
    void display();

    GT()
    {
        root = NULL;
    }
};

void GT::create_tree()
{
    int tbooks, tchapters, sections, sub_sec, i, j, k;
    root = new node();
    cout << "Enter name of book : ";
    cin.get();
    cin >> root->label;
    cout << "Enter number of chapters in book : ";
    cin >> tchapters;
    root->ch_count = tchapters;
    for (i = 0; i < tchapters; i++)
    {
        root->child[i] = new node();
        cout << "Enter the name of Chapter " << i + 1 << " : ";
        cin.get();
        cin >> root->child[i]->label;
        cout << "Enter number of sections in Chapter : " << root->child[i]->label << " : ";
        cin >> root->child[i]->ch_count;
        sections = root->child[i]->ch_count;
        for (j = 0; j < sections; j++)
        {
            root->child[i]->child[j] = new node();
            cout << "Enter Name of Section " << j + 1 << " : ";
            cin.get();
            cin >> root->child[i]->child[j]->label;
            cout << "Enter Number of subsections in " << root->child[i]->child[j]->label << " : ";
            cin >> root->child[i]->child[j]->ch_count;
            sub_sec = root->child[i]->child[j]->ch_count;
            for (k = 0; k < sub_sec; k++)
            {
                root->child[i]->child[j]->child[k] = new node();
                cout << "Enter name of Sub-section : " << k + 1 << " : ";
                cin.get();
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void GT::display()
{
    int i, j, k, tchapters;
    if (root != NULL)
    {
        cout << "\n-----Book Hierarchy---";
        cout << "\n Book title : " << root->label;
        tchapters = root->ch_count;
        for (i = 0; i < tchapters; i++)
        {

            cout << "\nChapter " << i + 1;
            cout << " : " << root->child[i]->label;
            cout << "\nSections : ";
            for (j = 0; j < root->child[i]->ch_count; j++)
            {
                cout << "\n"
                     << root->child[i]->child[j]->label;
                cout << "\n Sub-sections : ";
                for (k = 0; k < root->child[i]->child[j]->ch_count; k++)
                {
                    cout << "\n"
                         << root->child[i]->child[j]->child[k]->label << endl;
                    ;
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    int choice;
    GT gt;
    while (true)
    {
        cout << "-----------------" << endl;
        cout << "Book Tree Creation" << endl;
        cout << "-----------------" << endl;
        cout << "1.Create" << endl;
        cout << "2.Display" << endl;
        cout << "3.Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            gt.create_tree();
        case 2:
            gt.display();
            break;
        case 3:
            cout << "Thanks for using this program!!!";
            exit(1);
        default:
            cout << "Wrong choice!!!" << endl;
        }
    }
    return 0;
}