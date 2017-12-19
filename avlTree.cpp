#include "avlTree.h"
#include "iostream"
#include "fstream"
#include "string"
#include "doctor.h"
#include "patient.h"

template <typename T>
avlTree<T>::avlTree()
{
    key=NULL;
    left=NULL;
    right=NULL;
    height=0;
}

template <typename T>
avlTree<T>::avlTree(const avlTree<T>* copyFile)
{
    key=copyFile->key;
    left=copyFile->left;
    right=copyFile->right;
    height=copyFile->height;
}

template <typename T>
avlTree<T>::avlTree(T* key)
{
    this->key=key;
    left=NULL;
    right=NULL;
    height=0;
}


template <typename T>
avlTree<T>* avlTree<T>::deleteNodeProb(const string surname)
{
    avlTree<T>* root=this;
    bool f=true;
    const char*p = surname.c_str();
    const char*q = this->key->getSurname().c_str();
    while (*p&&*q && f)
        if (*p++!=*q++)
            f= false;

    if (this!=NULL)
    {
        if (f)
        {
            if (this->left==NULL && this->right==NULL)
            {
                delete root->key;
                delete root;
                return NULL;
            }
            else
                if (this->left!=NULL && this->right==NULL)
                {
                    avlTree<T>* rootForDel=root;
                    delete root->key;
                    root=root->left;
                    delete rootForDel;
                }
                else
                    if (this->left==NULL && this->right!=NULL)
                    {
                        avlTree<T>* rootForDel=root;
                        delete root->key;
                        root=root->right;
                        delete rootForDel;
                    }
                    else
                    {
                        avlTree<T>* root1=root->right;
                        if (root1->left!=NULL)
                            root->key=(deleteMin(&root1, &root));
                        else
                        {
                            root->key=(new T(root->right->key));
                            root->right=root->right->right;
                        }
                    }
        }
        else
            if (surname<this->key->getSurname())
                root->left=(this->left->deleteNodeProb(surname));
            else
                if (surname>this->key->getSurname())
                    root->right=(this->right->deleteNodeProb(surname));

        root=root->balanceAllTree(root);
        return root;
    }
    return NULL;
}

template <typename T>
T* avlTree<T>::deleteMin(avlTree<T>** root, avlTree<T>** root2)
{
    T* key;
    if ((*root)->left==NULL)
    {
        key=new T((*root)->key);
        (*root2)->left=((*root)->right);
        *root=(*root)->right;
        if (((*root2)->left->getHeight())>((*root2)->right->getHeight()))
        {
            (*root2)->height=((*root2)->left->getHeight()-1);
        }
        return key;
    }
    else
    {
        avlTree<T>* root1=(*root)->left;
        key=deleteMin(&root1, root);
        *root=root1;
        if (((*root2)->left->getHeight())>((*root2)->right->getHeight()))
        {
            (*root2)->height=((*root2)->left->getHeight());
        }
        return key;
    }
}

template <typename T>
avlTree<T>* avlTree<T>::addNode(T key)
{
    T *q=new T(key);
    return this->addNodeProb(q);
}

template <typename T>
avlTree<T>* avlTree<T>::addNode(doctor<string> key)
{
    doctor<string> *q=new doctor<string>(key);
    return this->addNodeProb(static_cast<T*>(q));
}

template <typename T>
avlTree<T>* avlTree<T>::addNode(patient<string> key)
{
    patient<string> *q=new patient<string>(key);
    return this->addNodeProb(static_cast<T*>(q));
}

template <typename T>
avlTree<T>* avlTree<T>::deleteNode(const string surname)
{
    return this->deleteNodeProb(surname);
}

template <typename T>
T* avlTree<T>::findVisitorProb(string surname){
    T* key;
    if (this!=NULL)
        if (surname<this->key->getSurname())
        {

            bool f=true;
            const char*p = surname.c_str();
            const char*q = this->getKey()->getSurname().c_str();
            while (*p&&*q && f)
                if (*p++!=*q++)
                    f= false;
            if (f)
                return this->key;
            else
                key=this->left->findVisitorProb(surname);
        }
        else
            if (surname>this->key->getSurname())
                key=this->right->findVisitorProb(surname);
            else
                return this->key;
    else
        return NULL;
    return key;
}

template <typename T>
T avlTree<T>::findVisitor(string surname){


    T* key1 = findVisitorProb(surname);
    if (key1!=NULL)
        return new T(key1);
    else
        return new T();

}

/*template <typename T>
avlTree<T>* avlTree<T>::addTreeFromFileProb(const string fileName){
    avlTree<T>* root=NULL;
    const char *cstr = fileName.c_str();
    ifstream in(cstr);
    delete(cstr);

    bool endOfFile=true;
    while (!in.eof())
    {
        string surname, name, patronymic, dish,
                phoneNumber, email, firstLine, blogAdress;
        if (in.eof())
            endOfFile=false;
        getline(in, firstLine);

        string line="critic";
        bool f=true;
        const char*p = firstLine.c_str();
        const char*q = line.c_str();
        while (*p&&*q && f)
            if (*p++!=*q++)
                f= false;

        getline(in, surname);
        if (in.eof())
            endOfFile=false;
        if (!in || surname=="")
            surname="No surname";

        getline(in, name);
        if (in.eof())
            endOfFile=false;
        if (!in || name=="")
            name="No name";

        getline(in, patronymic);
        if (in.eof())
            endOfFile=false;
        if (!in || patronymic=="")
            patronymic="No patronymic";

        getline(in, dish);
        if (in.eof())
            endOfFile=false;
        if (!in || dish=="")
            dish="No favourite dish";

        getline(in, phoneNumber);
        if (in.eof())
            endOfFile=false;
        if (!in)
        {
            if (phoneNumber=="")
                phoneNumber="No phone number";
            else
            {
                int sizeOfTelephneNumber=phoneNumber.size();
                bool flag=true;
                for(int i=1; i<sizeOfTelephneNumber;i++)
                    if (phoneNumber[i]<'0' or phoneNumber[i]>'9')
                        flag=false;
                if ((phoneNumber[0]<'0' or phoneNumber[0]>'9')
                        and phoneNumber[0]!='+')
                    flag=false;
                if (!(((sizeOfTelephneNumber==11 and phoneNumber[0]=='8')
                       or (sizeOfTelephneNumber==12 and phoneNumber[0]=='+'
                           and phoneNumber[1]=='7')
                       or (phoneNumber=="No phone number")) and flag))
                    phoneNumber="No phone number";
            }
        }

        getline(in, email);
        if (in.eof())
            endOfFile=false;
        if (!in)
        {
            if (email=="" or email=="No email")
                email="No email";
            else
            {
                int posOfDog = email.find('@');
                int posOfPoint = email.find('.');
                if (posOfDog==-1 or posOfPoint==-1)
                    email="example@gmail.com";
            }
        }

        if (f)
        {
            getline(in, blogAdress);
            if (!in || blogAdress=="")
                blogAdress="No blog adress";
        }

        if (endOfFile)
        {
            if (f)
            {
                root=root->addNode(criticT(surname, name, patronymic, dish,
                                           phoneNumber, email, blogAdress));
            }
            else
            {
                root=root->addNode(T(surname, name, patronymic, dish,
                                     phoneNumber, email));
            }
        }
    }
    in.close();
    return root;
}*/

/*template <typename T>
avlTree<T>* avlTree<T>::addTreeFromFile(const string fileName)
{
    avlTree<T>* root=new avlTree(this->addTreeFromFileProb(fileName));
    return root;
}*/

/*template <typename T>
void avlTree<T>::printIntoFile(const string outputFile){
    if (this!=NULL)
    {
        this->left->printIntoFile(outputFile);
        const char *cstr = outputFile.c_str();
        ofstream out(cstr, ios_base::app);
        delete(cstr);
        if (this->key->isCritic())
            out << "critic" << endl;
        else
            out << "not critic" << endl;
        out << this->key->getSurname() << endl;
        out << this->key->getName() << endl;
        out << this->key->getPatronymic() << endl;
        out << this->key->getDish() << endl;
        out << this->key->getPhoneNumber() << endl;
        out << this->key->getEmail() << endl;
        out.close();
        this->right->printIntoFile(outputFile);
    }
}*/

template <typename T>
avlTree<T>* avlTree<T>::addNodeProb(T* key){
    avlTree<T>* root=NULL;
    if (this==NULL)
    {
        root=new avlTree(key);
        return root;
    }
    else
    {
        root=this;
        if (key->getSurname()==this->key->getSurname())
        {
            if (key->getName()==this->key->getName()
                    and key->getPatronymic()==this->key->getPatronymic())
            {
                //this->key->setDish(key->getDish());
                //this->key->setEmail(key->getEmail());
                //this->key->setPhoneNumber(key->getPhoneNumber());
                return this;
            }
            else
            {
                this->left=(this->left->addNodeProb(key));
                root=this->balance(*key);
            }
        }
        if (key->getSurname()<this->key->getSurname())
        {
            this->left=(this->left->addNodeProb(key));
            root=this->balance(*key);
        }
        else
        {
            this->right=(this->right->addNodeProb(key));
            root=this->balance(*key);
        }
    }
    root->height=(max(this->left->getHeight(), this->right->getHeight())+1) ;
    return root;
}

template <typename T>
avlTree<T>* avlTree<T>::balanceAllTree(avlTree<T>* root)
{
    if (root!=NULL)
    {
        root->left=(balanceAllTree(root->left));

        root->right=(balanceAllTree(root->right));
        root=root->balanceForBalanceAllTree();
    }
    return root;
}

template <typename T>
avlTree<T>* avlTree<T>::balanceForBalanceAllTree()
{
    avlTree<T>* root=this;
    if ((this->left->getHeight()-this->right->getHeight())==2)
        root=srl(this);

    if ((this->right->getHeight()-this->left->getHeight())==2)
        root=srr(this);
    return root;
}

template <typename T>
avlTree<T>* avlTree<T>::balance(T key)
{
    avlTree<T>* root=this;

    if (key.getSurname()<=this->key->getSurname())
    {
        if ((this->left->getHeight()-this->right->getHeight())==2)
        {
            if (key.getSurname()<=this->left->key->getSurname())
                root=srl(this);
            else
                root=drl(this);
        }
    }
    else
    {
        if (key.getSurname()>this->key->getSurname())
            if ((this->right->getHeight()-this->left->getHeight())==2)
            {
                if (key.getSurname()>this->right->key->getSurname())
                    root=srr(this);
                else
                    root=drr(this);
            }
    }
    return root;
}

template <typename T>
avlTree<T>* avlTree<T>::srl(avlTree<T>* node)
{
    avlTree<T>* node2(node->left);
    node->left=(node2->right);
    node2->right=(node);
    node->height=(max(node->left->getHeight(), node->right->getHeight())+1);
    node2->height=(max(node2->left->getHeight(), node->getHeight())+1);
    return node2;
}

template <typename T>
avlTree<T>* avlTree<T>::srr(avlTree<T>* node)
{
    avlTree<T>* node2(node->right);
    node->right=(node2->left);
    node2->left=(node);
    node->height=(max(node->left->getHeight(), node->right->getHeight())+1);
    node2->height=(max(node->getHeight(), node2->right->getHeight())+1);
    return node2;
}

template <typename T>
avlTree<T>* avlTree<T>::drl(avlTree<T>* node)
{
    node->left=(srr(node->left));
    return srl(node);
}

template <typename T>
avlTree<T>* avlTree<T>::drr(avlTree<T>* node)
{
    node->right=(srl(node->right));
    return srr(node);
}

template <typename T>
T* avlTree<T>::getKey() const
{
    return this->key;
}

template <typename T>
avlTree<T>* avlTree<T>::getLeft()
{
    return this->left;
}

template <typename T>
avlTree<T>* avlTree<T>::getRight()
{
    return this->right;
}

template <typename T>
int avlTree<T>::getHeight() const
{
    if (this!=NULL)
        return this->height;
    else
        return -1;
}

/*template <typename T>
void avlTree<T>::printTree(int h)
{
    if (this!=NULL)
    {
        this->right->printTree(h+1);
        for (int i=0; i<h;i++) cout <<"---";
        cout << this->key->getSurname() <<endl;
        this->left->printTree(h+1);
    }
}*/

template <typename T>
int avlTree<T>::size() const
{
    if (this!=NULL)
        return this->right->size()+this->left->size()+1;
}

template <typename T>
void avlTree<T>::clear()
{
    cout<<"this (clear): "<<this<<endl;
     if (this!=NULL && (this->left!=NULL||this->right!=NULL))
     {
         cout<<"clearing"<<endl;
         this->getLeft()->clear();
         this->getRight()->clear();
         this->left=NULL;
         this->right=NULL;
     }
}

template <typename T>
void avlTree<T>::printTree(int h)
{
    cout<<"printTree - is to run"<<endl;
    if (this!=NULL)
    {
        cout<<"printTree - running"<<endl;
        this->right->printTree(h+1);
        for (int i=0; i<h;i++) cout <<"---";
        cout << this->key->getSurname() <<endl;
        this->left->printTree(h+1);
    }
}

template <typename T>
bool avlTree<T>::isEmpty() const
{
    if (this==NULL)
        return true;
    else
        return false;
}
template class avlTree<human>;
