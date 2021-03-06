#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

class binarySerialize
{
public:
    template <class T>
    static bool saveStruObject(string path, int len, T* content)
    {
        FILE *fp = fopen(path.data(), "wb");
        if (fp == NULL)
            return false;
        else
        {
            fwrite(content, sizeof(T), len, fp);
            fclose(fp);
            return true;
        }
    }

    template <class T>
    static bool loadStruObject(string path, int len, T* space)
    {
        FILE *fp = fopen(path.data(), "rb");
        if (fp == NULL)
            return false;
        else
        {
            fread(space, sizeof(T), len, fp);
            fclose(fp);
            return true;
        }
    }

    template <class T>
    static bool loadClasObject(string path, int len, T* space)
    {
        fstream infile(path, ios::in | ios::binary); //以读方式打开文件
        if (!infile)
            return false;
        else
        {
            infile.read((char*)space, sizeof(T)*len);
            infile.close();
            return true;
        }
    }

    template <class T>
    static bool saveClasObject(string path, int len, T* content)
    {
        fstream outfile(path, ios::app | ios::binary); //这里以app方式打开文件进行添加
        if (!outfile)
            return false;
        {
            outfile.write((char*)content, sizeof(T)*len);
            outfile.close();
            return true;
        }
    }

    static void creatFile(string path)
    {
        ofstream file(path, fstream::out);
        file.close();
    }

    template <class T, class T2>
    static bool loadSTLObject(string path, T& space)
    {
        int len;
        T2 *arr;
        ifstream read(path + ".len");
        if(!read)
            return false;
        else
        {
            read >> len;
            read.close();
            arr = new T2[len];
        }

        fstream infile(path, ios::ate|ios::out|ios::out|ios::binary); //以读方式打开文件
        if (!infile)
        {
            delete[]arr;
            return false;
        }
        else
        {
            infile.read((char*)arr, sizeof(T2)*len);
            infile.close();

            for (int i = 0; i < len; i++)
                space.push_back(arr[i]);

            delete []arr;
            return true;
        }
    }

    template <class T, class T2>
    static bool saveSTLObject(string path, T& content)
    {
        //创建文件
        creatFile(path);
        creatFile(path+".len");

        int len = content.size();
        T2 *arr = new T2[len]; //T2类型需要支持空构造函数和拷贝
        //复制STL内容到数组
        typename T::iterator iter = content.begin();
        for (int i = 0; iter != content.end(); iter++, i++)
            arr[i] = *iter;

        fstream outfile(path, ios::ate|ios::out|ios::in|ios::binary); //这里以app方式打开文件进行添加
        if (!outfile)
        {
            delete[]arr;
            return false;
        }
        else
        {
            outfile.write((char*)arr, sizeof(T2)*len);
            outfile.close();

            //记录len
            ofstream out(path + ".len");
            out << len;
            out.close();

            delete[]arr;
            return true;
        }
    }
};
