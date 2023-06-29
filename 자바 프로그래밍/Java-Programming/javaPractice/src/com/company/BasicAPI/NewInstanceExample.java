package com.company.BasicAPI;

public class NewInstanceExample {
    public static void main(String[] args) throws Exception {
        Class clazz = Class.forName("com.company.BasicAPI.SendAction");
//        Class clazz = Class.forName("com.company.BasicAPI.ReceiveAction");
        Action action = (Action) clazz.newInstance();
        action.execute();
    }
}

//데이터를 보냅니다.