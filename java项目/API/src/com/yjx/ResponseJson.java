package com.yjx;

import java.util.ArrayList;

import org.json.JSONObject;

public class ResponseJson {
	
    JSONObject json;
	
	public ResponseJson(int status,Object msg,ArrayList<JSONObject> data) {
		this.json = new JSONObject();
		json.put("msg", msg);
		json.put("status", status);
		json.put("data",data);
	}
	
	
	public JSONObject getResponseJson() {
		return this.json;
	}

}