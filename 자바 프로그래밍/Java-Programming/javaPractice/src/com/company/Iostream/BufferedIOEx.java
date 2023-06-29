package com.company.Iostream;

import java.io.BufferedOutputStream;
import java.io.InputStreamReader;

public class BufferedIOEx {
    public static void main(String[] args) throws Exception{
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedOutputStream out = new BufferedOutputStream(System.out, 5);

        int c;
        while((c = in.read()) != -1) {
            out.write(c);
        }

        out.flush(); // 버퍼에 남아있던 문자 출력

        if(in != null) {
            in.close();
            out.close();
        }
    }
}

//12345678
//12345^D
//678