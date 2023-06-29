package com.company.Iostream;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class CreateSerFile {
    public static void main(String[] args) {
        ObjectOutputStream output;
        try {
            output = new ObjectOutputStream(new FileOutputStream("./src/com/company/iostream/UserInfo.ser"));

            UserInfo u1 = new UserInfo("JavaMan", "1234", 30);
            UserInfo u2 = new UserInfo("JavaWoman", "4321", 20);

            ArrayList<UserInfo> list = new ArrayList<>();
            list.add(u1);
            list.add(u2);

            output.writeObject(list);
            output.close();
            System.out.println("직렬화 완료");

        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}

//직렬화 완료