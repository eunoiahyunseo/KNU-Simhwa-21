package com.company.Iostream;

import java.io.FileReader;

public class FileReaderEx {
    public static void main(String[] args) throws Exception {
        FileReader in  = new FileReader("./test.txt");;
        int c;
        char[] cbuf = new char[2];
        String data = "";

        while((c = in.read(cbuf, 0, 2)) != -1) {
            data += new String(cbuf, 0, c);
        }

        System.out.println(data);
        in.close();
    }
}

//Hello World!
//Hello Hyunseo!