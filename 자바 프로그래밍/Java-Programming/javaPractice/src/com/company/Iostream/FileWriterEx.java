package com.company.Iostream;

import java.io.FileWriter;
import java.io.InputStreamReader;

public class FileWriterEx {
    public static void main(String[] args) throws Exception{
        FileWriter out = new FileWriter("./test2.txt");
        char[] data = "hyunseo is\nhandsome".toCharArray();

        out.write(data);

        out.flush();
    }
}
