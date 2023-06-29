package com.company.Iostream;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class BinaryCopy {
    public static void main(String[] args) throws Exception{
        File src = new File("./images/img.jpg");
        File dest = new File("./src/com/company/iostream/img.jpg");

        int c;

        FileInputStream fi = new FileInputStream(src);
        FileOutputStream fo = new FileOutputStream(dest);

        while((c = fi.read()) != -1) {
            fo.write((byte)c);
        }

        fi.close();
        fo.close();
        System.out.println(src.getPath() + "를 " + dest.getPath() + "로 복사하였습니다.");
    }
}

//./images/img.jpg를 ./src/com/company/iostream/img.jpg로 복사하였습니다.