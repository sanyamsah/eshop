package com.sanyam.eshop_backend.eshop_rest_api.repository;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Role;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface RoleRepository extends JpaRepository<Role, Long> {
    Optional<Role> findByName(String name);
    void deleteByName(String name);
}
