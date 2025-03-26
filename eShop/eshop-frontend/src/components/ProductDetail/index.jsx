import axios from 'axios';
import React, { useState, useEffect } from 'react';
import './styles.css';
import { useParams } from 'react-router-dom';

const ProductDetail = () => {
    const {id} = useParams();
    const [productDetail, setProductDetail] = useState({});
    const getProductDetail = async () => {
        try {
            const response = await axios.get(`https://api.escuelajs.co/api/v1/products/${id}`);
            setProductDetail(response.data);
        } catch (error) {
            console.log(error);
        }
    }
    useEffect(() => {
        getProductDetail();
    }, [id]);
    return (
        <div className="container">
            <div className="row">
                <div className="col-md-6"> {/* Added margin-bottom for spacing */}
                    <div className="wrapper">
                        <img src={productDetail.images} className="img-fluid" /> {/* Fixed className */}
                    </div>
                </div>
                <div className="col-md-6">
                    <div className="wrapper">
                        <h5 className="card-title">{productDetail.title}</h5>
                        <h6>
                            <span className="badge badge-pill badge-secondary">{productDetail.category?.name}</span>
                        </h6>
                        <p className="card-text">
                            {productDetail.description}
                        </p>
                        <h2>
                            <span>&#36;</span>{productDetail.price}
                        </h2>
                        <button className="btn btn-primary btn-block" type="submit">
                            Add to Cart
                        </button>
                    </div>
                </div>
            </div>
        </div>
    );
}

export default ProductDetail;