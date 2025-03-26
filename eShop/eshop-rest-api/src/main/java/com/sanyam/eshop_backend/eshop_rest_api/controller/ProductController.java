package com.sanyam.eshop_backend.eshop_rest_api.controller;

import com.sanyam.eshop_backend.eshop_rest_api.entity.Product;
import com.sanyam.eshop_backend.eshop_rest_api.service.ProductService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@CrossOrigin(origins = "*", maxAge = 3600)
@RestController
@RequestMapping("/api/categories")
public class ProductController {
    @Autowired
    private ProductService productService;

    @GetMapping("/{categoryId}/products")
    public ResponseEntity<List<Product>> getProductsFromCategory(@PathVariable("categoryId") Long categoryId){
        var data = productService.getAllProducts(categoryId);
        return ResponseEntity.ok(data);
    }

    @GetMapping("/{categoryId}/products/{productId}")
    public ResponseEntity<Product> getProductById(@PathVariable("categoryId") Long categoryId,
                                                  @PathVariable("productId") Long productId){
        var data = productService.getProductById(categoryId, productId);
        return ResponseEntity.ok(data);
    }

    @PostMapping("/{categoryId}/products")
    public ResponseEntity<Product> createProduct(@PathVariable("categoryId") Long categoryId,
                                                 @RequestBody Product newProduct){
        var data = productService.createProduct(categoryId, newProduct);
        return ResponseEntity.ok(data);
    }

    @PutMapping("/{categoryId}/products/{productId}")
    public ResponseEntity<Product> updateProduct(@PathVariable("categoryId") Long categoryId,
                                                 @PathVariable("productId") Long productId,
                                                 @RequestBody Product updatedProduct){
        var data = productService.updateProduct(categoryId, productId, updatedProduct);
        return ResponseEntity.ok(data);
    }

    @DeleteMapping("/{categoryId}/products/{productId}")
    public ResponseEntity<Void> deleteProduct(@PathVariable("categoryId") Long categoryId,
                                              @PathVariable("productId") Long productId){
        productService.deleteProduct(categoryId, productId);
        return ResponseEntity.noContent().build();
    }
}
