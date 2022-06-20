#pragma once

#include <algorithm>
#include <cmath>
#include <string>
#include <deque>

namespace minmax
{
    class Node
    {
    private:
        int value;
        Node *left;
        Node *right;

    protected:
        int max_value_ab(int alpha, int beta)
        {
            if (left == nullptr || right == nullptr) // LEAF NODE
                return value;
            int minmax_value_l = left->min_value_ab(alpha, beta);

            alpha = std::max(minmax_value_l,alpha);

            if (alpha >= beta) // PRUNE
                return minmax_value_l;

            int minmax_value_r = right->min_value_ab(alpha, beta);

            return std::max(minmax_value_l, minmax_value_r);
        }

        int min_value_ab(int alpha, int beta)
        {
            if (left == nullptr || right == nullptr) // LEAF NODE
                return value;
            int minmax_value_l = left->max_value_ab(alpha, beta);

            beta = std::min(minmax_value_l,beta);

            if (alpha >= beta) // PRUNE
                return minmax_value_l;

            int minmax_value_r = right->max_value_ab(alpha, beta);

            return std::min(minmax_value_l, minmax_value_r);
        }

        int min_value()
        {
            if (left == nullptr || right == nullptr)
                return value;

            return std::min(left->max_value(), right->max_value());
        }

        int max_value()
        {
            if (left == nullptr || right == nullptr)
                return value;

            return std::max(left->min_value(), right->min_value());
        }

    private:

        void add_nodes_level(int l, std::deque<int> &q, int current_level=0){
            if(current_level==l){
                q.push_back(this->value);
                return;
            }
            if(left!=nullptr)
                left->add_nodes_level(l,q,current_level+1);
            if(right!=nullptr)
                right->add_nodes_level(l,q,current_level+1);
        }

        void breadth_visit(std::deque<int> &q){
            for(int l=0;l<height();l++){
                std::cout<<"Aggiungo nodi di livello "<<l<<std::endl;
                add_nodes_level(l,q);
                std::cout<<"In coda "<<q.size()<<" nodi"<<std::endl;
            }
        }

    public:
        Node(int v, Node *l, Node *r)
        {
            value = v;
            left = l;
            right = r;
        }

        int alpha_beta()
        {
            return max_value_ab(INT32_MIN, INT32_MAX);
        }

        int min_max()
        {
            return this->max_value();
        }

        std::string *str()
        {
            std::string *txt = new std::string;
            std::deque<int> printqueue;
            breadth_visit(printqueue);
            std::cout << "Size " << printqueue.size() << std::endl;
            int level = 0;
            while (!printqueue.empty())
            {
                for (int i = 0; i < pow(2, level) && !printqueue.empty(); i++)
                {
                    if (printqueue.front() == 0)
                        txt->append("K").append(std::to_string(level)).append(" ");
                    else
                        txt->append(std::to_string(printqueue.front())).append(" ");
                    printqueue.pop_front();
                }
                level++;
                txt->append("\n");
            }
            return txt;
        }

        int height(){
            int left_h = 0,right_h=0;
            if(left != nullptr)
                left_h = left->height();
            if(right != nullptr)
                right_h = right->height();
            return 1+ std::max(left_h,right_h);
        }

        bool is_leaf()
        {
            return right == nullptr && left == nullptr;
        }
    };
}