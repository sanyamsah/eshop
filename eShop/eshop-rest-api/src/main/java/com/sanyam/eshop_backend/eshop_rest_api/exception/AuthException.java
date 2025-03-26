package com.sanyam.eshop_backend.eshop_rest_api.exception;

import org.springframework.http.HttpStatus;

public class AuthException extends RuntimeException{
    private HttpStatus status;
    private String message;

    public HttpStatus getStatus() {
        return status;
    }

    public void setStatus(HttpStatus status) {
        this.status = status;
    }

    @Override
    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public AuthException(HttpStatus status, String message){
        this.status = status;
        this.message = message;
    }
}