import React, { useState, useEffect, use } from 'react';
import axios from 'axios';
import Products from '../Products';
import ApiClient from '../../client/ApiClient';

const ProductList = () => {
    const [products, setProducts] = useState([]);
    // const getProductList = () => {
    //     axios.get('https://api.escuelajs.co/api/v1/products')
    //         .then(response => setProducts(response.data))
    //         .catch(error => console.log(error));
    // }
    const getProductList = () => {
        ApiClient.get("/products") 
            .then(response => setProducts(response.data))
            .catch(error => console.log(error));
    }
    useEffect(() => {
        getProductList();
    }, []);
    return(
        <div className="container">
            <h2 className='text-center'>All Products</h2>
            <div className="row">
                {
                    products.map((product, index) => (<Products data={product} key={index}/>))
                }
            </div>
        </div>
    );
}

export default ProductList;