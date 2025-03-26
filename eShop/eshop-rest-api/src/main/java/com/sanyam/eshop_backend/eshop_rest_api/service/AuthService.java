package com.sanyam.eshop_backend.eshop_rest_api.service;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Role;
import com.sanyam.eshop_backend.eshop_rest_api.payload.LoginDTO;
import com.sanyam.eshop_backend.eshop_rest_api.payload.RegisterDTO;

import java.util.List;

public interface AuthService {
    String register(RegisterDTO registerDTO);
    String login(LoginDTO loginDTO);
    String createRole(Role role);
    String deleteRole(String name);
    List<Role> getAllRoles();
    String getRoleByName(String name);
}
