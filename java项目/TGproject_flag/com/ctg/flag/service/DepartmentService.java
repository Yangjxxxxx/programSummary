package com.ctg.flag.service;

import com.ctg.flag.pojo.entity.Department;

import java.util.List;


public interface DepartmentService {
    /**
     * 查询身份验证码
     * @param authCode
     * @return
     */
    Department findByAuthCode(String authCode);

    /**
     * 返回所属机构列表
     * @return
     */

    List<Department> findAllByKind();
}
