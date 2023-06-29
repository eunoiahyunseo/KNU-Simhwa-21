package com.company.Iostream;

import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class ReadSerFile {
    public static void main(String[] args) {
        ObjectInputStream input;

        try {
            input = new ObjectInputStream(new FileInputStream("./src/com/company/iostream/UserInfo.ser"));
            ArrayList list = (ArrayList) input.readObject();
            input.close();
            System.out.println(list);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}
//[(JavaMan,1234,30), (JavaWoman,4321,20)]
