package com.company.Exception;

public class BalanceInsufficientException extends Exception{
    public BalanceInsufficientException() {  }
    public BalanceInsufficientException(String message) {
        super(message);
    }
}
