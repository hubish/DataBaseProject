#ifndef avlTree_H
#define avlTree_H
#include "string"
#include "doctor.h"
#include "patient.h"

using namespace std;
template <typename T>
class avlTree
{
private:
    T *key;
    avlTree<T> *left;
    avlTree<T> *right;
    int height;

    avlTree<T>* balanceForBalanceAllTree();
    avlTree<T>* balance(T key);
    avlTree<T>* balanceAllTree(avlTree<T>* root);
    int maxCol(string dish);
    avlTree<T>* srl(avlTree<T>* node);
    avlTree<T>* srr(avlTree<T>* node);
    avlTree<T>* drl(avlTree<T>* node);
    avlTree<T>* drr(avlTree<T>* node);
    avlTree<T>* addNodeProb(T *key);


    int getHeight() const;
    T* deleteMin(avlTree<T>** root, avlTree<T>** root2); //Óäàëÿåò ìèíèìàëüíûé ýëåìåíò äåðåâà
    //avlTree<T>* addTreeFromFileProb(const string fileName);
    avlTree<T>* deleteNodeProb(const string surname);


public:
    avlTree<T>* getLeft();
    avlTree<T>* getRight();
    T* getKey() const;
    avlTree<T>();
    avlTree<T>(const avlTree<T>* copyFile);
    avlTree<T>(T* key);
    void clear();

    //avlTree<T>* addTreeFromFile(const string fileName);

    avlTree<T>* addNode(T key);
    avlTree<T>* addNode(doctor<string> key);
    avlTree<T>* addNode(patient<string> key);

    avlTree<T>* deleteNode(const string surname);

    void printTree(int h);
    //void printIntoFile(const string outputFile);
    T findVisitor(string surname);
    T* findVisitorProb(string surname);
    int size() const;
    bool isEmpty() const;
};

#endif // avlTree_H
