/*
 * @name: Muntherr anati
 * @Id: 1182028
 * Date: 10/1/2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h> //Library to declare several useful functions

typedef struct AVLTREE *Tptr;
typedef struct HashTable Hptr;
typedef struct Meanings *Mptr;

struct AVLTREE
{
    char word[50]; //longest word in the world has 45 letters, so the number of indices should be greater than 45
    char synonym[20];
    char antonym[20];
    Mptr MeaningN; //for N number of meanings, I create a linked list of its meanings
    Tptr Left;
    Tptr Right;
    int Height; //Balance information
    int c;
};
struct Meanings
{
    char meaning[30];
    Mptr next;
};

struct HashTable
{
    char key[30];
    Mptr MeaningN; //for N number of meanings, I create a linked list of meanings
    char Synonym[30];
    char antonym[30];
    int isEmpty;
};
void TreeMenu();
Tptr readfile();
Tptr MakeEmpty(Tptr T);
Mptr LMakeEmpty(Mptr L);
void DeleteList(Mptr L);
int Height(Tptr P);
Tptr Insert(char dword[], char sword[], char aword[], Tptr T, Mptr M);
Tptr Add_word(Tptr AVL);
Tptr SingleRotateWithLeft(Tptr K2);
Tptr SingleRotateWithRight(Tptr K1);
Tptr DoubleRotateWithLeft(Tptr K3);
Tptr DoubleRotateWithRight(Tptr K1);
int Max(int Lhs, int Rhs);
Tptr FindMin(Tptr T);
Tptr FindMax(Tptr T);
void Printlexicographic(Tptr t);
void printAll(Tptr head);
void prints(Tptr t, int b);
Tptr Search(Tptr T, char Word[], int b);
Tptr LSearch(Tptr T, char L);
Tptr Update(Tptr T, int b);
int first_letter(Tptr t, char l);
Tptr deleteNode(Tptr T, char word[]);
void printPostorder(Tptr node);
void Export(Tptr t, FILE *fout);
void Mexport(Tptr head, FILE *fout);
int getBalanceFactor(Tptr T);
Tptr Letter_Deletion(Tptr root, char word);
void dfirst_letter(Tptr t, char L);
void insert_hashtable(Hptr ht[], char *key, char *synonym, char *antonym, Mptr M, int size);
int hash_main();
void HashMenu();
void ReadHashfile(Hptr[], int size);
int Kyecount();
int HashTableSize(int x);
int Isprime(int a);
int Tablesize(int x);
void Creat_table(Hptr hashtable[], int size);
unsigned long long String_hash(char *key, int HashTableSize);
int Prime_smaller_Tablesize(int tablesize);
int Double_hash(unsigned long H1, int Lp, int Tablesize, int i);
void HashprintMeaning(Hptr Ht[], int i);
void Insert_new_record(Hptr[], int);
int Hash_Search(Hptr[], char key[], int);
void print_hashtable(Hptr hashtable[], int i);
void Export_to_File(Hptr hashtable[], int size);
int ReHash(Hptr hashtable[], int size);

Tptr LSearch(Tptr T, char L);

int main()
{
    Tptr AVL = MakeEmpty(NULL);
    Tptr S = MakeEmpty(NULL);
    Tptr temp;
    FILE *fout;
    Mptr Llist;
    int t, plural = 0;
    char Sword[30], Saword[30], L, D[50], tmp, De;
    int choice;
    printf("\n");
    TreeMenu();
    scanf("%d", &choice);
    while (choice)
    {

        switch (choice)
        {
        case 1:
        {
            AVL = readfile();

            break;
        }
        case 2:
            AVL = Add_word(AVL);
            break;
        case 3:
            printf("\t\tEnter a word to find it:");
            scanf("%s", Sword);
            Search(AVL, Sword, 0);
            break;
        case 4:
        {
            Printlexicographic(AVL);
            printf("\n\t\t###########################################\n");
        }
        break;
        case 5:
        {
            printf("\t\tEnter a word to print Synonym and antonym:");
            scanf("%s", Saword);
            Search(AVL, Saword, 1);
        }
        break;
        case 6:
        {
            printf("\n\t\tEnter a letter:");
            scanf(" %s", &L);
            t = first_letter(AVL, L);
            if (t == 0)
            {
                printf("\n\t\tSorry, The dictionary is under development. There are no words that start with the \'%s\' letter ):\n", &L);
            }
        }
        break;
        case 7:
        {
            printf("\n\t\tEnter the word to delete it:");
            scanf("%c", &tmp);
            scanf("%[^\n]", D);
            AVL = deleteNode(AVL, D);
            printf("\n\t\tThe word is deleted successfuly.\n");
        }
        break;
        case 8:
        {
            printf("\n\t\tEnter a letter:");
            scanf(" %s", &De);
            temp = LSearch(AVL, De); //Search for word with specific letter
            while (temp != NULL)     //Trace all node
            {
                temp = LSearch(AVL, De);
                if (temp != NULL)
                    AVL = Letter_Deletion(AVL, temp->word[0]); //Delete all words with specific letter.
                plural++;
            }
            if (plural == 1)
                printf("\n\t\tThe word is deleted successfuly.\n");
            else
                printf("\n\t\tAll words with specific letter are deleted successfuly.\n");
            break;
        }
        case 9:
        {
            fout = fopen("Dictionary.data", "w"); // Open file to export the data and read it again in hash function.
            Export(AVL, fout);
            fclose(fout);
            printf("\t\tData exported to file successfuly.\n");
        }
        break;
        case 10:
            hash_main();
            break;

        default:
            printf("\n\t\tPlease choose a valid choice from 1 to 10 !! \n");
            break;
        }
        printf("\n");

        TreeMenu();
        scanf("%d", &choice);
    }
}

int hash_main()
{

    int size = 0, i, Fsize = 0, Index, DeleteIndex;
    int H1, tablesize, Db;
    int choice;
    char tmp;
    char SearchKey[50];
    HashMenu();

    Fsize = Kyecount(); // Determine number of keys in the file to know number of size for hash table.
    size = Tablesize(Fsize);
    Hptr hashtable[size];
    Creat_table(hashtable, size);  //Set hash table to default value.
    ReadHashfile(hashtable, size); //Read Dictionary file, if the file doesn't be as default format it will not run!!!
    scanf("%d", &choice);

    while (choice)
    {
        switch (choice)
        {
        case 1:
        {

            for (int i = 0; i < size; i++)
            {
                print_hashtable(hashtable, i);
            }
            printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t");
        }
        break;
        case 2:
        {
            printf("\n\t\tTable size is: %d\n", size);
        }
        break;
        case 3:
        {

            printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2");
            printf("\t\t\t\t\t\t   \xB2\n\t\t\xB2    %c Fisrt I used String hash function:\t    \xB2\n\t\t\xB2\t\t\t\t\t\t   \xB2\n\t\t\xB2 int hash(char* key, int TableSize){\t\t   \xB2"
                   "\n\t\t\xB2 int hashValue = 0;\t\t\t\t   \xB2"
                   "\n\t\t\xB2\twhile (*key != \'\\0\' ){\t\t\t   \xB2"
                   "\n\t\t\xB2\t\t hashValue += *key++;}\t\t   \xB2"
                   "\n\t\t\xB2 return (hashValue %c TableSize);}\t\t   \xB2\n\t\t\xB2",
                   254, 37);
            printf("\t\t\t\t\t\t   \xB2\n\t\t\xB2\t\t\t\t\t\t   \xB2\n\t\t\xB2    %c Second I used The Double Hash function,\t   \xB2\n\t\t\xB2 I used it to get the indicies for all words:\t   \xB2\n\t\t"
                   "\xB2\t\"h(x) = h1(x) + i * h2(x)\"\t\t   \xB2\n\t\t\xB2\t\t\t\t\t\t   \xB2\n ",
                   254);
            printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        }
        break;
        case 4:
        {
            Insert_new_record(hashtable, size);
        }
        break;
        case 5:
        {
            printf("\t\tEnter Key to find it:");
            scanf("%c", &tmp);
            scanf("%[^\n]", SearchKey);
            Index = Hash_Search(hashtable, SearchKey, size); //Find the Index for Wanted key then return it to print it.
            if (Index != -1)
            {
                print_hashtable(hashtable, Index);
                printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t");
            }
            else
            {
                printf("\n\t\tSorry, Key doesn't Exist in the Table.\n");
            }
        }
        break;
        case 6:
        {
            SearchKey[0] = '\0';
            printf("\t\tEnter Key to delete it:");
            scanf("%c", &tmp);
            scanf("%[^\n]", SearchKey);
            DeleteIndex = Hash_Search(hashtable, SearchKey, size);
            if (DeleteIndex != -1) //Return all data to default value
            {
                hashtable[DeleteIndex].key[0] = '\0';
                hashtable[DeleteIndex].Synonym[0] = '\0';
                hashtable[DeleteIndex].antonym[0] = '\0';
                hashtable[DeleteIndex].isEmpty = -1;
                hashtable[DeleteIndex].MeaningN = NULL;
                printf("\n\t\tKey deleted sucessfully.\n");
            }
            else
                printf("\n\t\tSorry, Key doesn't Exist in the Table.\n");
        }
        break;
        case 7:
        {
            Export_to_File(hashtable, size);
        }
        break;
        case 8:
        {
            return 0;
        }
        break;
        default:
            printf("\t\tPlease choose a valid choice from 1 to 8 !! \n");
            break;
        }
        HashMenu();
        scanf("%d", &choice);
    }
}
int ReHash(Hptr hashtable[], int size)
{
    //Do REHASH
    int count = 0;
    int Checksize = 0;
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i].isEmpty == 0)
            count++; //Count number of the words in the hash table
    }
    Checksize = size * 0.75;
    if (count > Checksize) //If the size table is almost full change the size table and insert them
    {

        printf("Count -> %d = size=%d\n", count, size);
        size = size * 2; //New table size
        if (Isprime(size) == 0)
            size = Prime_smaller_Tablesize(size);

        printf("%d", size);
        for (int i = 0; i < size; i++)
        {
        }
        return size;
    }
    else
        return size;
}
void Export_to_File(Hptr hashtable[], int size)
{
    FILE *Fout;
    Fout = fopen("Dictionary.data", "w");
    for (int i = 0; i < size; i++)
    {
        if (hashtable[i].isEmpty == -1)
        {
            fprintf(Fout, "%d-[Empty spot]\n", i + 1); //If there is any emprt spots then print [Empty spot].
        }
        else
        {
            Mptr p = LMakeEmpty(NULL);
            int j = 0;
            fprintf(Fout, "%d-Key->%c%s.\n", i + 1, toupper(hashtable[i].key[0]), hashtable[i].key + 1);
            fprintf(Fout, "Values->\n"); //Values are 1.meanings 2.synonym 3.Antonym.

            p = hashtable[i].MeaningN;
            fprintf(Fout, "\t\t\ta.Meanings:\n");
            while (p != NULL)
            {
                fprintf(Fout, "\t\t\t\t%d-%c%s.\n", j + 1, toupper(p->meaning[0]), strlwr(p->meaning + 1));
                p = p->next;
                j++;
            }
            // HashprintMeaning(hashtable, i); //Print All Meaning in the hashed table for each key.
            fprintf(Fout, "\t\t\tb.Synonym->%c%s.\n", toupper(hashtable[i].Synonym[0]), strlwr(hashtable[i].Synonym + 1));
            fprintf(Fout, "\t\t\tc.Antonym->%c%s.\n", toupper(hashtable[i].antonym[0]), strlwr(hashtable[i].antonym + 1));
        }
    }
    fclose(Fout);
}
void print_hashtable(Hptr hashtable[], int i)
{
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\t\t\xB2");
    if (hashtable[i].isEmpty == -1)
    {
        printf("\n\t\t\xB2 %d-[Empty spot]\n\t\t\xB2", i + 1); //If there is any emprt spots then print [Empty spot].
    }
    else
    {
        printf("\n\t\t\xB2 %d-Key->%c%s\t\t\n", i + 1, toupper(hashtable[i].key[0]), hashtable[i].key + 1);
        printf("\t\t\xB2   Values->\n"); //Values are 1.meanings 2.synonym 3.Antonym.
        HashprintMeaning(hashtable, i);  //Print All Meaning in the hashed table for each key.
        printf("\t\t\xB2\tb.Synonym->%c%s\n", toupper(hashtable[i].Synonym[0]), strlwr(hashtable[i].Synonym + 1));
        printf("\t\t\xB2\tc.Antonym->%c%s\n\t\t\xB2", toupper(hashtable[i].antonym[0]), strlwr(hashtable[i].antonym + 1));
    }
}
int Hash_Search(Hptr hashTable[], char key[], int size)
{

    if (hashTable == NULL)
    {
        printf("Error, Empty hash table\n");
        return -1;
    }

    unsigned long H1 = 0;
    unsigned int HashIndex = 0;
    int Sp = 0, i = 0;
    H1 = String_hash(strlwr(key), size); //H1 for string hash value, I used String hash function to calculate string value then i save it as H1.
    Sp = Prime_smaller_Tablesize(size);  //This function gets the first number is smaller than the size.

    while (i <= size)
    {

        HashIndex = Double_hash(H1, Sp, size, i); //Double hash function have H1+i*H2, H2 = first small prime number than size - H1 % first small prime number than size.
        HashIndex = HashIndex % size;             //All hash Index value mod the size of the table.
        if (!(strcasecmp(hashTable[HashIndex].key, key)))
        {
            return HashIndex; //return word Index if found
        }
        else if (hashTable[i].isEmpty == 0)
            i++;
        else if (hashTable[i].isEmpty == -1)
            return -1;
    }
    return -1; //return -1 means that the
}
void Insert_new_record(Hptr hashtable[], int size)

{

    size = ReHash(hashtable, size);

    Mptr temp = NULL;
    Mptr ptr = NULL;
    Mptr new_Mlist = NULL;

    char new_word[50];
    char new_meaning[30];
    char new_synonym[20];
    char new_antonym[20];
    char tmp = '\0';
    int choice = 1;
    char ch;
    int i = 0;
    printf("\t\tTo add a new Recoed to the Hash table, Enter the Following:-\n");
    printf("\t\tThe new Key \"Word\" :");
    scanf("%c", &tmp);         // To read Full word with spaces i used temporary buffer to clear any input data in new word string
    scanf("%[^\n]", new_word); // %[^\n] to read till hit Enter
    printf("\t\tEnter Values for new key:-\n");

    while (choice >= 1)
    {

        printf("\t\tEnter a meaning:");
        scanf("%c", &tmp);
        scanf("%[^\n]", new_meaning);
        ptr = LMakeEmpty(ptr); //Take all meaning and save them in linked list
        strcpy(ptr->meaning, new_meaning);
        ptr->next = NULL;
        if (new_Mlist == NULL)
            new_Mlist = ptr;
        else
        { //Fined new node to save the next linked list contents
            temp = new_Mlist;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }

        i++;
        if (i != 3)
        {
            printf("\t\tDo you want to add another meaning \"Up to three meaning\"\n");
            printf("\t\t(Y/N):");
            scanf(" %s", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                choice = 1;
            }
            else if (ch == 'N' || ch == 'n')
            {
                choice = 0;
                break;
            }
            else
            {
                printf("\t\tPlease Enter Valid input (Y,N)\n");
                return;
            }
        }
        else
        {
            printf("\t\tYou have reached the maximum of meanings words allowed.\n");
            break;
        }
    }

    printf("\t\tEnter a synonym:"); //Take A synonym from user
    scanf("%c\n", &tmp);
    scanf("%s", new_synonym);

    printf("\t\tEnter an antonym:"); //Take A synony from user
    scanf("%c", &tmp);
    scanf("%[^\n]", new_antonym);
    insert_hashtable(hashtable, new_word, new_synonym, new_antonym, new_Mlist, size); //Insert new Word to the tree
}
void HashprintMeaning(Hptr Ht[], int i)
{ //Print All meanings for each words in Hash
    int j = 0;
    Mptr p = LMakeEmpty(NULL);

    p = Ht[i].MeaningN;
    printf("\t\t\xB2\ta.Meanings:\n");
    while (p != NULL)
    {
        printf("\t\t\xB2\t\t%d-%c%s\n", j + 1, toupper(p->meaning[0]), strlwr(p->meaning + 1));
        p = p->next;
        j++;
    }
}
int Double_hash(unsigned long H1, int Lp, int Tablesize, int i) //Lp is a prime smaller than TableSize
{
    unsigned long H2;
    int DoubleHash;
    H2 = Lp - (H1 % Lp);
    DoubleHash = (H1 % Tablesize) + (i * H2);
    return DoubleHash;
}
int Prime_smaller_Tablesize(int tablesize) //This function to find a prime number smaller than Tablesize
{
    tablesize--;
    int flag = Isprime(tablesize);
    while (flag != 1)
    {
        tablesize--;
        flag = Isprime(tablesize);
    }
    return tablesize;
}
void Creat_table(Hptr hashtable[], int size) //initialize all hashtable contents
{

    Mptr p = LMakeEmpty(NULL);
    for (int i = 0; i < size; i++)
    {

        hashtable[i].key[0] = '\0';
        hashtable[i].Synonym[0] = '\0';
        hashtable[i].antonym[0] = '\0';
        hashtable[i].isEmpty = -1;
        hashtable[i].MeaningN = p;
    }
}
void insert_hashtable(Hptr hT[], char *key, char *synonym, char *antonym, Mptr M, int size)
{
    unsigned long H1 = 0;
    unsigned int HashIndex = 0;
    int Sp = 0, i = 0;
    H1 = String_hash(strlwr(key), size); //H1 for string hash value, I used String hash function to calculate string value then i save it as H1.
    Sp = Prime_smaller_Tablesize(size);  //This function gets the first number is smaller than the size.

    while (i <= size)
    {

        HashIndex = Double_hash(H1, Sp, size, i); //Double hash function have H1+i*H2, H2 = first small prime number than size - H1 % first small prime number than size.
        HashIndex = HashIndex % size;             //All hash Index value mod the size of the table.

        if (hT[HashIndex].isEmpty == -1)
        {
            strcpy(hT[HashIndex].key, key);
            strcpy(hT[HashIndex].Synonym, synonym);
            strcpy(hT[HashIndex].antonym, antonym);
            hT[HashIndex].MeaningN = M;
            hT[HashIndex].isEmpty = 0;
            break;
        }
        else
        {
            i++; //If the Hash index isn't Empty then increment i by one till get empty hash node.
        }
    }
    return;
}
unsigned long long String_hash(char *key, int HashTableSize)
{

    unsigned long long hashValue = 0;
    while (*key != '\0')
    {
        hashValue = (hashValue << 5) + *key++; //Bit shifting by 5
    }
    return hashValue;
}
int Kyecount()
{
    // count the number of keys to find the best size for the hash table.
    FILE *fp = fopen("Dictionary.txt", "r");
    int ch = 0;
    int keys = 0;

    if (fp == NULL)
        return 0;

    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch == ':')
        {
            keys++;
        }
    }
    fclose(fp);
    return keys;
}
void ReadHashfile(Hptr Ht[], int size)
{
    Mptr Mlist;
    int i = 0;
    Mlist = LMakeEmpty(NULL);
    Mptr temp = NULL;
    Mptr ptr = NULL;
    Mlist = NULL;

    FILE *File;
    File = fopen("Dictionary.data", "r");
    int Fsize = Kyecount();

    char line[100];
    char data[20][50];
    char rest[100];

    char *wtok, *mtok, *atok, *stok;
    if (Fsize == 0)
    {
        printf("\n\t\tError, Empty file!!\n");
        exit(0);
    }

    while (!feof(File))
    {

        temp = NULL; //to make linked list empty for next Tree information
        ptr = NULL;
        Mlist = NULL;
        fgets(line, 100, File);
if(*line == NULL)
    continue;
       

        else
        {
            strcpy(rest, line);              //copy all lines to rest var to split all meanings for each word in the file.
            strcpy(rest, strtok(rest, " ")); //remove the word
            strcpy(rest, strtok(NULL, "/")); // remove all synonym and antonym, just to keep all meanings
            mtok = strtok(rest, ",");
            //In this while loop, I will use a linked list to save all meaning for each word
            //save meaning inside linked list, then go to the next node in it to save the next meaning until mtok be NULL
            while (mtok != NULL)
            {
                ptr = LMakeEmpty(ptr);
                if (mtok[0] == ' ')
                {
                    mtok++; //if first char in the string is == space then i will remove it by make the first pointer point to the next one
                }
                strcpy(ptr->meaning, mtok);
                ptr->next = NULL;
                if (Mlist == NULL)
                    Mlist = ptr;
                else
                {
                    temp = Mlist;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = ptr;
                }
                // printf("-%s-\n", ptr->meaning);
                mtok = strtok(NULL, ",");
                //  mtok = strtok(NULL, "");
            }
            wtok = strtok(line, ":"); //Used strtok to split the words and there synonym , antonym and meaning of it
            // mtok = strtok(NULL, ",");
            stok = strtok(NULL, "/"); //strtok to split synonym of words and then remove spaces
            stok = strtok(NULL, " ");
            atok = strtok(NULL, " * .\n"); //to split the antonym and remove spaces and new lines if its last word

            insert_hashtable(Ht, wtok, stok, atok, Mlist, size); //Insert All word and its information to tree to save it
            i++;
        }
    }
}

int Isprime(int a) // Check if the number is a prime number or not.
{
    int i;
    for (i = 2; i < a; i++) // all number divisible by 1, so the loop starts from 2
        if (a % i == 0)     // if a mod i == 0 then it isn't prime number
            return 0;
    if (i == a) //Prime number is a number that is divisible only by itself and 1
        return 1;
}
int Tablesize(int x)
{
    x = x * 2; //Hash size is the first prime number that is greater than or equal to 2 * size
    int flag = Isprime(x);
    while (flag != 1)
    {
        x++;
        flag = Isprime(x);
    }
    return x;
}

Tptr LSearch(Tptr T, char L) //This function to search for the word with specific letter
{

    if (T == NULL)
        return NULL;
    if ((tolower(L)) < (tolower(T->word[0])))
    {
        return LSearch(T->Left, L);
    }
    else if ((tolower(L)) > (tolower(T->word[0])))
    {
        return LSearch(T->Right, L);
    }
    else // if (!(strcmp(strlwr(Word), strlwr(T->word))))
    {
        if (T != NULL)
            return T;
    }

    //if (!(strcasecmp(Word, T->word)))
}
Tptr Search(Tptr T, char Word[], int b) // Search for specific word
{
    if (T == NULL)
    {
        printf("\n\t\tSorry, the Word isn't found.\n");
        return NULL;
    }
    if (strcmp(strlwr(Word), strlwr(T->word)) < 0) // IF the specific word is smaller than current word then go left
    {
        return Search(T->Left, Word, b);
    }
    else if (strcasecmp(Word, T->word) > 0) // IF the specific word is greater than current word then go right
    {
        return Search(T->Right, Word, b);
    }
    else
    {
        if (T != NULL)
            return Update(T, b);
    }
}

Tptr Letter_Deletion(Tptr T, char L)
{
    //first will do a Standard BST deletion
    if (T == NULL)
    {
        return T;
    }
    // if letter is smaller than fist letter in the word then go left
    if (tolower(L) < tolower(T->word[0]))
        T->Left = Letter_Deletion(T->Left, L);
    //if letter is greater than fist letter in the word then go right
    else if (tolower(L) > tolower(T->word[0]))
        T->Right = Letter_Deletion(T->Right, L);
    else
        //  if word is same as the T word's, then This is the node to be deleted
        if (T->Left == NULL || T->Right == NULL)
    {                                             // node with two children
        Tptr temp = T->Left ? T->Left : T->Right; //temp == T->left if root->left != NULL else temp = T->right
        if (temp == NULL)
        {
            temp = T;
            T = NULL;
        }
        else
        {
            *T = *temp;
        }
        free(temp);
    }
    else
    {
        Tptr temp = FindMin(T->Right); // node with only one child or no child.
        //Copy all temp data to The T node
        strcpy(T->word, temp->word);
        strcpy(T->antonym, temp->antonym);
        strcpy(T->synonym, temp->synonym);
        T->MeaningN = temp->MeaningN;
        T->Right = Letter_Deletion(T->Right, temp->word[0]);
    }
    // If the tree had only one node then return.
    if (T == NULL)
    {

        return T;
    }

    //Balancing steps.
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    int balance = getBalanceFactor(T);
    if (balance > 1 && getBalanceFactor(T->Left) >= 0)
        return SingleRotateWithLeft(T);
    if (balance > 1 && getBalanceFactor(T->Left) < 0)
    {
        return DoubleRotateWithLeft(T);
    }
    if (balance < -1 && getBalanceFactor(T->Right) <= 0)
        return SingleRotateWithRight(T);
    if (balance < -1 && getBalanceFactor(T->Right) > 0)
    {
        return DoubleRotateWithRight(T);
    }
    return T;
}
Tptr deleteNode(Tptr root, char word[])

{

    //first will do a Standard BST deletion
    if (root == NULL)
    {
        printf("Sorry, The Word isn't found\n");
        return root;
    }
    //If the key to be deleted is smaller than the root's key, then it lies in left subtree.
    if (strcasecmp(word, root->word) < 0)
        root->Left = deleteNode(root->Left, word);
    //  If the key to be deleted is greater than the root's key, then it lies in right subtree.
    else if (strcasecmp(word, root->word) > 0)
        root->Right = deleteNode(root->Right, word);
    else
    { // if key is same as root's key, then This is the node to be deleted
        if (root->Left == NULL || root->Right == NULL)
        {                                                      // node with two children
            Tptr temp = root->Left ? root->Left : root->Right; //temp == root->left if root->left != NULL else temp = root->right
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            Tptr temp = FindMin(root->Right); // node with only one child or no child.
            // Copy the content of the node to the tree to free the min node for balancing.
            strcpy(root->word, temp->word);
            strcpy(root->antonym, temp->antonym);
            strcpy(root->synonym, temp->synonym);
            root->MeaningN = temp->MeaningN;
            root->Right = deleteNode(root->Right, temp->word);
        }
    } // If the tree had only one node then return.
    if (root == NULL)
    {
        return root;
    }
    //Balancing steps
    root->Height = Max(Height(root->Left), Height(root->Right)) + 1;
    int balance = getBalanceFactor(root);
    if (balance > 1 && getBalanceFactor(root->Left) >= 0)
        return SingleRotateWithLeft(root);
    if (balance > 1 && getBalanceFactor(root->Left) < 0)
    {
        return DoubleRotateWithLeft(root);
    }
    if (balance < -1 && getBalanceFactor(root->Right) <= 0)
        return SingleRotateWithRight(root);
    if (balance < -1 && getBalanceFactor(root->Right) > 0)
    {
        return DoubleRotateWithRight(root);
    }
    return root;
}
Tptr Update(Tptr T, int b)
{
    //This function update specific word enterd b
    char new_meaning[30];
    char old_meaning[30];
    char new_synonym[20];
    char new_antonym[20];
    char ch, tmp;
    char c;
    if (b == 1)
    {
        prints(T, 1);
        return 0;
    }

    else if (b == 0)
    {
        if (T != NULL)
        {
            int flag = 0;

            prints(T, 0);
            printf("\n\t\t###########################################\n");
            printf("Do you want to update the information of the word?\n(Y/N):");
            scanf(" %s", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                printf("\t\tChoose from list:\n");
                printf(
                    "\t\t   1-Update meanings.\n"
                    "\t\t   2-Update a synonym.\n"
                    "\t\t   3-Update an antonym.\n"
                    "\t\t   4-Back to main menu.\n"
                    "\t\tYour choice-->>");
                scanf("%s", &c);

                while (c != 4)
                {

                    switch (c)
                    {
                    case '1':
                        printf("Enter the meaning to update:");
                        scanf("%c", &tmp);
                        scanf("%[^\n]", old_meaning);
                        Mptr p = LMakeEmpty(NULL); // To update the meaning for specific word from tree.
                        p = T->MeaningN;
                        while (p != NULL)
                        {
                            if (strcasecmp(p->meaning, old_meaning) == 0)
                            {
                                printf("Enter a new meaning to update:");
                                scanf("%c", &tmp);
                                scanf("%[^\n]", new_meaning);
                                strcpy(p->meaning, new_meaning);
                                flag = 1;
                                break;
                            }
                            else
                                flag = 0;

                            p = p->next;
                        }
                        if (flag == 0)
                            printf("Sorry, the meaning you want to search for isn't found.\n");

                        break;
                    case '2':

                        printf("Enter a new antonym:");
                        scanf("%c", &tmp);
                        scanf("%[^\n]", new_antonym);
                        strcpy(T->antonym, new_antonym);
                        // printf("%s", T->synonym);
                        break;
                    case '3':
                        printf("Enter a new synonym:");
                        scanf("%c", &tmp);
                        scanf("%[^\n]", new_synonym);
                        strcpy(T->synonym, new_synonym);
                        // printf("%s", T->synonym);
                        break;
                    case '4':
                        return 0;
                    default:
                        printf("\t\tPlease Enter a valid choice\n");
                        break;
                    }
                    printf("\t\tChoose from list:\n");
                    printf(
                        "\t\t   1-Update meanings.\n"
                        "\t\t   2-Update a synonym.\n"
                        "\t\t   3-Update an antonym.\n"
                        "\t\t   4-Back to main menu.\n"
                        "\t\tYour choice-->>");
                    scanf("%s", &c);
                }
            }
            else if (ch == 'N' || ch == 'n')
            {
                return T;
                //break;
            }
            else
            {
                printf("Please Enter Valid input (Y,N)\n");
                return 0;
            }
        }

        return T;
    }
}
Tptr Add_word(Tptr new_Avl)
{
    //Tptr new_Avl;
    Mptr temp = NULL;
    Mptr ptr = NULL;
    Mptr new_Mlist = NULL;
    // new_Avl = MakeEmpty(NULL);
    char new_word[50];
    char new_meaning[30];
    char new_synonym[20];
    char new_antonym[20];
    char tmp = '\0';
    int choice = 1;
    char ch;
    int i = 0;
    printf("\t\tTo add a new word to the Dictionary, Enter the Following:-\n");
    printf("\t\tThe new Word:");
    scanf("%c", &tmp);         // To read Full word with spaces i used temporary buffer to clear any input data in new word string
    scanf("%[^\n]", new_word); // %[^\n] to read till hit Enter

    while (choice >= 1)
    {

        printf("\t\tEnter a meaning:");
        scanf("%c", &tmp);
        scanf("%[^\n]", new_meaning);
        ptr = LMakeEmpty(ptr); //Take all meaning and save them in linked list
        strcpy(ptr->meaning, new_meaning);
        ptr->next = NULL;
        if (new_Mlist == NULL)
            new_Mlist = ptr;
        else
        { //Fined new node to save the next linked list contents
            temp = new_Mlist;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
        }

        i++;
        if (i != 3)
        {
            printf("\t\tDo you want to add another meaning \"Up to three meaning\"\n");
            printf("\t\t(Y/N):");
            scanf(" %s", &ch);
            if (ch == 'Y' || ch == 'y')
            {
                choice = 1;
            }
            else if (ch == 'N' || ch == 'n')
            {
                choice = 0;
                break;
            }
            else
            {
                printf("\n\t\tPlease Enter Valid input (Y,N)\n");
                return new_Avl;
            }
        }
        else
        {
            printf("\n\t\tYou have reached the maximum of meanings words allowed.\n");
            break;
        }
    }

    printf("\t\tEnter a synonym:"); //Take A synonym from user
    scanf("%c\n", &tmp);
    scanf("%s", new_synonym);

    printf("\t\tEnter an antonym:"); //Take A synony from user
    scanf("%c", &tmp);
    scanf("%[^\n]", new_antonym);
    new_Avl = Insert(new_word, new_synonym, new_antonym, new_Avl, new_Mlist); //Insert new Word to the tree
    return new_Avl;
}
Tptr Insert(char dword[], char sword[], char aword[], Tptr T, Mptr M)
{

    if (T == NULL)
    {
        /* Create and return a one-node tree with all information for each word */
        T = (Tptr)malloc(sizeof(struct AVLTREE));

        if (T == NULL)
            printf("\t\tOut of space!!!");
        strcpy(T->word, dword);
        strcpy(T->synonym, sword);
        strcpy(T->antonym, aword);
        T->MeaningN = M;
        T->Height = 0;
        T->Left = T->Right = NULL;
        return T;
    }
    //strcasecmp it is an builtin function that comparing between two string with ignoring the case characters.
    else if (strcasecmp(dword, T->word) < 0)
    { // If inserted word is less than to current word in the node then go to the left
        T->Left = Insert(dword, sword, aword, T->Left, M);

        if (Height(T->Left) - Height(T->Right) >= 2)
        {                                             //Balancing the tree nodes, if the height greater than 2 then i do rotation.
            if (strcasecmp(dword, T->Left->word) < 0) // if the word less than current word do a Single rotation to the left
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (strcasecmp(dword, T->word) > 0)
    {
        T->Right = Insert(dword, sword, aword, T->Right, M);
        if (Height(T->Right) - Height(T->Left) >= 2)
        {
            if (strcasecmp(dword, T->Left->word) > 0)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    /* Else X is in the tree already; we'll do nothing */
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}
Tptr readfile()
{ //In Readfile() function i will read words from file name "Words.txt",then split if to (word , its meaning , synonym, antonym).

    Tptr Avl;
    Mptr Mlist;
    Mlist = LMakeEmpty(NULL);
    Avl = MakeEmpty(NULL);
    Mptr temp = NULL;
    Mptr ptr = NULL;
    Mlist = NULL;
    FILE *File;
    File = fopen("Words.txt", "r");
    char line[100];
    char data[20][50];
    char rest[100];
    char *wtok, *mtok, *atok, *stok;

    while (!feof(File))
    {

        temp = NULL; //to make linked list empty for next Tree information
        ptr = NULL;
        Mlist = NULL;
        fgets(line, 100, File);
        if (*line == '\n' && *line == '\r' && *line == ' ')
        {
            *line = '\0';
        }
        else
        {
            strcpy(rest, line);              //copy all lines to rest var to split all meanings for each word in the file.
            strcpy(rest, strtok(rest, " ")); //remove the word
            strcpy(rest, strtok(NULL, "/")); // remove all synonym and antonym, just to keep all meanings
            mtok = strtok(rest, ",");
            //In this while loop, I will use a linked list to save all meaning for each word
            //save meaning inside linked list, then go to the next node in it to save the next meaning until mtok be NULL
            while (mtok != NULL)
            {
                ptr = LMakeEmpty(ptr);
                if (mtok[0] == ' ')
                {
                    mtok++; //if first char in the string is == space then i will remove it by make the first pointer point to the next one
                }
                strcpy(ptr->meaning, mtok);
                ptr->next = NULL;
                if (Mlist == NULL)
                    Mlist = ptr;
                else
                {
                    temp = Mlist;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = ptr;
                }
                mtok = strtok(NULL, ",");
            }
            wtok = strtok(line, ":"); //Used strtok to split the words and there synonym , antonym and meaning of it
            // mtok = strtok(NULL, ",");
            stok = strtok(NULL, "/"); //strtok to split synonym of words and then remove spaces
            stok = strtok(NULL, " ");
            atok = strtok(NULL, " * .\n");              //to split the antonym and remove spaces and new lines if its last word
            Avl = Insert(wtok, stok, atok, Avl, Mlist); //Insert All word and its information to tree to save it
        }
    }

    return Avl;
}
Mptr LMakeEmpty(Mptr L) //Make linked list empty to store meaning to it.
{
    if (L != NULL)
        DeleteList(L);
    L = (Mptr)malloc(sizeof(struct Meanings));
    if (L == NULL)
        printf("Out of memory!\n");
    return L;
}
void DeleteList(Mptr L) //To delete linked list and make sure that it is empty.
{
    Mptr P;
    Mptr temp = NULL;
    P = L->next;
    L->next = NULL;

    while (P != NULL)
    {
        temp = P->next;
        free(P);
        P = temp;
    }
}
Tptr MakeEmpty(Tptr T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
int Height(Tptr P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}
void printAll(Tptr head)
{ //Print All meanings for each words
    int i = 0;
    Mptr p = LMakeEmpty(NULL);

    p = head->MeaningN;
    printf("\t\tMEANINGS:\n");
    while (p != NULL)
    {
        printf("\t\t\t%d-%s\n", i + 1, strlwr(p->meaning));
        p = p->next;
        i++;
    }
}
int first_letter(Tptr t, char L)
{
    int flag = 0;
    Tptr p = MakeEmpty(NULL);
    p = t;
    if (p != NULL)
    {
        first_letter(p->Left, L);
        if (tolower(p->word[0]) == tolower(L)) //If The entered letter == the first letter in the words,it will print all the smae first letter words
        {
            printf("\n\t\t###########################################\n\t\tWORD    : %s\n", strlwr(p->word));
            printAll(p);
            printf("\t\tSYNONYM : %s\n", strlwr(p->synonym));
            printf("\t\tANTONYM : %s", strlwr(p->antonym));
            flag = 1;
        }
        first_letter(p->Right, L);
    }

    return flag;
}
void Mexport(Tptr head, FILE *fout)
{ //Print meanings for each words
    int i = 0;
    Mptr p = LMakeEmpty(NULL);

    p = head->MeaningN;
    //printf("MEANINGS:\n");
    while (p != NULL)
    {
        if (p->next == NULL)
        {
            fprintf(fout, " %s", strlwr(p->meaning));
        }
        else
            fprintf(fout, " %s,", strlwr(p->meaning));
        p = p->next;
        i++;
    }
}
void Export(Tptr t, FILE *fout) //This Recursive function for print the data to file
{

    if (t != NULL)
    {
        Export(t->Left, fout);
        fprintf(fout, "\n%s:", strlwr(t->word));
        Mexport(t, fout);
        fprintf(fout, "/ %s", strlwr(t->synonym));
        fprintf(fout, "* %s\n", strlwr(t->antonym));
        Export(t->Right, fout);
    }
}
void Printlexicographic(Tptr t) //This Recursive function for print the data in lexicographic order(Inorder)
{
    if (t != NULL)
    {
        Printlexicographic(t->Left);
        printf("\n\t\t###########################################\n\t\tWORD    : %s\n", strlwr(t->word));
        printAll(t);
        //printf("--%c--", t->word[0]);
        printf("\t\tSYNONYM : %s\n", strlwr(t->synonym));
        printf("\t\tANTONYM : %s", strlwr(t->antonym));
        Printlexicographic(t->Right);
    }
}
void prints(Tptr t, int b)
{ /* This function used to print the for two function if b = 1 , the it will print just the word, a synonym and an antonym.
                            if b = 0, it will print all word information with its meanings.*/

    //  printf(">>>");
    if (b == 1)
    {
        printf("\n\t\t###########################################\n\t\tWORD    : %s\n", strlwr(t->word));
        printf("\t\tSYNONYM : %s\n", strlwr(t->synonym));
        printf("\t\tANTONYM : %s", strlwr(t->antonym));
    }
    else if (b == 0)
    {
        printf("\n\t\t###########################################\n\t\tWORD    : %s\n", strlwr(t->word));
        printAll(t);
        printf("\t\tSYNONYM : %s\n", strlwr(t->synonym));
        printf("\t\tANTONYM : %s", strlwr(t->antonym));
        return;
    }
}
Tptr SingleRotateWithLeft(Tptr K2)
{
    Tptr K1 = K2->Left;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), Height(K2->Right)) + 1;
    return K1; /* New root */
}
Tptr SingleRotateWithRight(Tptr K1)
{
    Tptr K2;
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Right), Height(K1->Right)) + 1;
    return K2; /* New root */
}
Tptr DoubleRotateWithLeft(Tptr K3)
{
    /* Rotate between K1 and K2 */
    K3->Left = SingleRotateWithRight(K3->Left);

    /* Rotate between K3 and K2 */
    return SingleRotateWithLeft(K3);
}
Tptr DoubleRotateWithRight(Tptr K1)
{
    /* Rotate between K3 and K2 */
    K1->Right = SingleRotateWithLeft(K1->Right);

    /* Rotate between K1 and K2 */
    return SingleRotateWithRight(K1);
}
int getBalanceFactor(Tptr T)
{
    if (T == NULL)
        return 0;
    return Height(T->Left) - Height(T->Right);
}
Tptr FindMin(Tptr T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}
Tptr FindMax(Tptr T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;

    return FindMax(T->Right);
}
int Max(int Lhs, int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

void TreeMenu()
{

    printf("\t\t-------------------------------------------\n"
           "\t\t-->>Welcome to The extensive dictionary<<--\n"
           "\t\t-------------------------------------------\n"
           "\t\tPlease Choose from list below:\n"
           "\t\t   1-Read Words from file.\n"
           "\t\t   2-ADD new word with associated data.\n"
           "\t\t   3-Search for a word.\n"
           "\t\t   4-List All words.\n"
           "\t\t   5-List All synonym and antonyms of word.\n"
           "\t\t   6-List All words with the specific letter.\n"
           "\t\t   7-Delete a Word.\n"
           "\t\t   8-Delete a word with the specific letter.\n"
           "\t\t   9-Export the data to file \"Dictionary.data\".\n"
           "\t\t   10-Go to hash menu.\n"
           "\t\t-------------------------------------------\n"
           "\t\tYour choice-->>");
}
void HashMenu()
{
    printf("\n\t\t-------------------------------------------\n"
           "\t\t-->Welcome to hashing functions<<--\n"
           "\t\t-------------------------------------------\n"
           "\t\t   1-Print Hashed table.\n"
           "\t\t   2-Print table size.\n"
           "\t\t   3-Print the used hashed function.\n"
           "\t\t   4-Insert new record to the hash table.\n"
           "\t\t   5-Search for a word.\n"
           "\t\t   6-delete a specific record.\n"
           "\t\t   7-Save hash table to the file \"Dictionary.data\".\n"
           "\t\t   8-Return to main menu.\n"
           "\t\t-------------------------------------------\n"
           "\t\tYour choice-->>");
}