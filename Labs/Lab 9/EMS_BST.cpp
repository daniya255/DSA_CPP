#include <iostream>
#include <string>

using namespace std;

class EmployeeNode
{
public:
    int id;
    string name;
    string department;
    EmployeeNode *left;
    EmployeeNode *right;

    EmployeeNode(int empId, string empName, string empDept)
    {
        id = empId;
        name = empName;
        department = empDept;
        left = nullptr;
        right = nullptr;
    }
};

class EmployeeBST
{
private:
    EmployeeNode *root;

    EmployeeNode *insertRec(EmployeeNode *node, int id, string name, string department)
    {
        if (node == nullptr)
        {
            return new EmployeeNode(id, name, department);
        }

        if (id < node->id)
        {
            node->left = insertRec(node->left, id, name, department);
        }
        else if (id > node->id)
        {
            node->right = insertRec(node->right, id, name, department);
        }
        else
        {
            cout << "Employee with ID " << id << " already exists.\n";
        }
        return node;
    }

    EmployeeNode *searchRec(EmployeeNode *node, int id)
    {
        if (node == nullptr || node->id == id)
        {
            return node;
        }
        if (id < node->id)
        {
            return searchRec(node->left, id);
        }
        return searchRec(node->right, id);
    }

    EmployeeNode *findMinNode(EmployeeNode *node)
    {
        EmployeeNode *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    EmployeeNode *findMaxNode(EmployeeNode *node)
    {
        EmployeeNode *current = node;
        while (current && current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    EmployeeNode *deleteRec(EmployeeNode *node, int id)
    {
        if (node == nullptr)
            return node;

        if (id < node->id)
        {
            node->left = deleteRec(node->left, id);
        }
        else if (id > node->id)
        {
            node->right = deleteRec(node->right, id);
        }
        else
        {

            if (node->left == nullptr)
            {
                EmployeeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                EmployeeNode *temp = node->left;
                delete node;
                return temp;
            }

            EmployeeNode *temp = findMinNode(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->department = temp->department;

            node->right = deleteRec(node->right, temp->id);
        }
        return node;
    }

    void inOrderRec(EmployeeNode *node)
    {
        if (node != nullptr)
        {
            inOrderRec(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Department: " << node->department << "\n";
            inOrderRec(node->right);
        }
    }

public:
    EmployeeBST()
    {
        root = nullptr;
    }

    void insert(int id, string name, string department)
    {
        root = insertRec(root, id, name, department);
    }

    void search(int id)
    {
        EmployeeNode *result = searchRec(root, id);
        if (result != nullptr)
        {
            cout << "Employee Found -> ID: " << result->id << ", Name: " << result->name << ", Department: " << result->department << "\n";
        }
        else
        {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }

    void deleteNode(int id)
    {
        root = deleteRec(root, id);
    }

    void inOrderTraversal()
    {
        inOrderRec(root);
    }

    void findMin()
    {
        EmployeeNode *minNode = findMinNode(root);
        if (minNode != nullptr)
        {
            cout << "Employee with Smallest ID -> Name: " << minNode->name << ", Department: " << minNode->department << " (ID: " << minNode->id << ")\n";
        }
        else
        {
            cout << "The employee tree is empty.\n";
        }
    }

    void findMax()
    {
        if (root == nullptr)
        {
            cout << "The employee tree is empty.\n";
            return;
        }
        EmployeeNode *current = root;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        cout << "Employee with Largest ID -> Name: " << current->name << ", Department: " << current->department << " (ID: " << current->id << ")\n";
    }
};

int main()
{
    EmployeeBST companyTree;

    // Testing insertion
    companyTree.insert(105, "Alice Smith", "HR");
    companyTree.insert(102, "Bob Jones", "Engineering");
    companyTree.insert(110, "Charlie Brown", "Finance");
    companyTree.insert(101, "Diana Prince", "Marketing");
    companyTree.insert(108, "Ethan Hunt", "Engineering");

    cout << "--- Employee Records (In-Order Traversal) --- \n";
    companyTree.inOrderTraversal();

    cout << "\n--- Search Operations --- \n";
    companyTree.search(102);
    companyTree.search(999);

    cout << "\n--- Boundary Operations --- \n";
    companyTree.findMin();
    companyTree.findMax();

    cout << "\n--- Deleting Employee ID 102 --- \n";
    companyTree.deleteNode(102);

    cout << "--- Updated Records --- \n";
    companyTree.inOrderTraversal();

    return 0;
}