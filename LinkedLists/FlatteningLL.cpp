//
// Created by prawi on 30-05-2021.
//

Node *merge(Node* head1,Node* head2)
{

    Node* dummyNode = new Node(0);
    Node* dummyHead = dummyNode;

    while( head1 != nullptr && head2 != nullptr )
    {
        if( head1->data <= head2->data )
        {
            dummyNode->bottom = head1;
            head1 = head1->bottom;
        }
        else
        {
            dummyNode->bottom = head2;
            head2 = head2->bottom;
        }
        dummyNode = dummyNode -> bottom;
    }


    while( head1 != nullptr)
    {
        dummyNode->bottom = head1;
        head1 = head1->bottom;
        dummyNode = dummyNode->bottom;
    }

    while( head2 != nullptr)
    {
        dummyNode->bottom = head2;
        head2 = head2->bottom;
        dummyNode = dummyNode->bottom;
    }

    return dummyHead->bottom;
}

Node *flatten(Node *root)
{
    Node* curr = root;
    while( curr->next != nullptr )
    {
        root = merge(root,curr->next);
        curr = curr->next;
    }

    return root;
}


