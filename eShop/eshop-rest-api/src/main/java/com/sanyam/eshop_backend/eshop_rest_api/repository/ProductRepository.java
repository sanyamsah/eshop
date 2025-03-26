package com.sanyam.eshop_backend.eshop_rest_api.repository;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Product;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

public interface ProductRepository extends JpaRepository<Product, Long> {
    List<Product> findByCategoryId(Long categoryId);
}
