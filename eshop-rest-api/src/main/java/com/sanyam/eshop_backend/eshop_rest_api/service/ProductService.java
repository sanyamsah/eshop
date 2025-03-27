package com.sanyam.eshop_backend.eshop_rest_api.service;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Product;

import java.util.List;

public interface ProductService {
    List<Product> getAllProducts();
    List<Product> getAllProducts(Long categoryId);
    Product getProductById(Long categoryId, Long productId);
    Product getProductById(Long productId);
    Product createProduct(Long categoryId, Product newProduct);
    Product updateProduct(Long categoryId, Long productId, Product updatedProduct);
    void deleteProduct(Long categoryId, Long productId);
}
